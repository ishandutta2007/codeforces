#![allow(unused_imports, unused_macros, non_snake_case)]
use std::cmp::{max, min, Ordering};
use std::collections::{BTreeMap, BTreeSet, BinaryHeap, HashMap, HashSet, VecDeque};

fn run() {
    let stdin = std::io::stdin();
    let mut sc = Scanner::new(stdin.lock());
    let t: usize = sc.read();
    for _ in 0..t {
        let n: usize = sc.read();
        let a: Vec<usize> = sc.read_vec(n);
        let mut lists: HashMap<usize, Vec<usize>> = HashMap::new();
        for (i, x) in a.iter().enumerate() {
            lists.entry(*x).or_default().push(i);
        }
        let mut answer = usize::max_value();
        for (_, v) in lists {
            for is in v.windows(2) {
                answer.set_min(is[1] - is[0] + 1);
            }
        }
        println!(
            "{}",
            if answer == usize::max_value() {
                -1
            } else {
                answer as isize
            }
        );
    }
}

fn main() {
    std::thread::Builder::new()
        .name("run".to_string())
        .stack_size(256 * 1024 * 1024)
        .spawn(run)
        .unwrap()
        .join()
        .unwrap()
}

//{{{ utils
pub struct Scanner<R> {
    reader: R,
}

impl<R> Scanner<R> {
    pub fn new(r: R) -> Scanner<R> {
        Scanner { reader: r }
    }
}

fn is_whitespace(b: u8) -> bool {
    b == b' ' || b == b'\n' || b == b'\r' || b == b'\t'
}

impl<R: std::io::Read> Scanner<R> {
    pub fn read<T: std::str::FromStr>(&mut self) -> T {
        let buf = std::io::Read::bytes(self.reader.by_ref())
            .map(|b| b.expect("Read failed"))
            .skip_while(|&b| is_whitespace(b))
            .take_while(|&b| !is_whitespace(b))
            .collect::<Vec<_>>();
        unsafe { std::str::from_utf8_unchecked(&buf) }
            .parse()
            .ok()
            .expect("Parse error")
    }

    pub fn read_vec<T: std::str::FromStr>(&mut self, n: usize) -> Vec<T> {
        (0..n).map(|_| self.read()).collect()
    }

    pub fn read_chars(&mut self) -> Vec<char> {
        self.read::<String>().chars().collect()
    }
}

pub trait SetMinMax {
    fn set_min(&mut self, v: Self) -> bool;
    fn set_max(&mut self, v: Self) -> bool;
}

impl<T> SetMinMax for T
where
    T: PartialOrd,
{
    fn set_min(&mut self, v: T) -> bool {
        *self > v && {
            *self = v;
            true
        }
    }
    fn set_max(&mut self, v: T) -> bool {
        *self < v && {
            *self = v;
            true
        }
    }
}

#[derive(PartialEq, Eq, Debug, Copy, Clone, Default, Hash)]
pub struct Reverse<T>(pub T);

impl<T: PartialOrd> PartialOrd for Reverse<T> {
    #[inline]
    fn partial_cmp(&self, other: &Reverse<T>) -> Option<Ordering> {
        other.0.partial_cmp(&self.0)
    }

    #[inline]
    fn lt(&self, other: &Self) -> bool {
        other.0 < self.0
    }
    #[inline]
    fn le(&self, other: &Self) -> bool {
        other.0 <= self.0
    }
    #[inline]
    fn ge(&self, other: &Self) -> bool {
        other.0 >= self.0
    }
    #[inline]
    fn gt(&self, other: &Self) -> bool {
        other.0 > self.0
    }
}

impl<T: Ord> Ord for Reverse<T> {
    #[inline]
    fn cmp(&self, other: &Reverse<T>) -> Ordering {
        other.0.cmp(&self.0)
    }
}
//}}}