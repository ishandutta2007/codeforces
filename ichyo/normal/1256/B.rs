#![allow(unused_imports, unused_macros, non_snake_case)]
use std::cmp::{max, min, Ordering};
use std::collections::{BTreeMap, BTreeSet, BinaryHeap, HashMap, HashSet, VecDeque};

fn run() {
    let stdin = std::io::stdin();
    let mut sc = Scanner::new(stdin.lock());
    let q: usize = sc.read();
    for _ in 0..q {
        let n: usize = sc.read();
        let mut a: Vec<usize> = sc.read_vec(n);
        let mut used: HashSet<usize> = HashSet::new();
        for _ in 0..n {
            let idx = (0..n - 1)
                .filter(|idx| !used.contains(idx))
                .filter(|&idx| a[idx] > a[idx + 1])
                .min_by_key(|&idx| a[idx + 1]);
            if let Some(idx) = idx {
                a.swap(idx, idx + 1);
                used.insert(idx);
            }
        }
        for x in a {
            print!("{} ", x);
        }
        print!("\n");
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