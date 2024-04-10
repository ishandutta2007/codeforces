#![allow(unused_imports, unused_macros, non_snake_case)]
use std::cmp::Ordering::{self, Greater, Less};
use std::cmp::{max, min};
use std::collections::{BTreeMap, BTreeSet, BinaryHeap, HashMap, HashSet, VecDeque};
use std::io::{self, BufReader, BufWriter, Read, Write};

fn solve<R: Read, W: Write>(mut sc: Scanner<R>, mut w: BufWriter<W>) {
    let t: usize = sc.read();
    for _ in 0..t {
        let a: i64 = sc.read();
        let b: i64 = sc.read();
        let sum = a + b;
        let ans = if sum % 3 == 0 {
            let x = sum / 3;
            if a >= x && b >= x && a <= 2 * x && b <= 2 * x {
                "YES"
            } else {
                "NO"
            }
        } else {
            "NO"
        };
        writeln!(w, "{}", ans);
    }
}

fn run() {
    let stdin = io::stdin();
    let stdout = io::stdout();

    let input = stdin.lock();
    let output = BufWriter::new(stdout.lock());

    solve(Scanner::new(input), output);
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
pub struct Tokenizer<R: std::io::Read> {
    reader: R,
}

impl<R: std::io::Read> Tokenizer<R> {
    pub fn new(r: R) -> Tokenizer<R> {
        Tokenizer { reader: r }
    }
}

fn is_whitespace(b: u8) -> bool {
    b == b' ' || b == b'\n' || b == b'\r' || b == b'\t'
}

impl<R: std::io::Read> std::iter::Iterator for Tokenizer<R> {
    type Item = String;
    fn next(&mut self) -> Option<Self::Item> {
        let buf = std::io::Read::bytes(self.reader.by_ref())
            .map(|b| b.unwrap_or(b' '))
            .skip_while(|&b| is_whitespace(b))
            .take_while(|&b| !is_whitespace(b))
            .collect::<Vec<_>>();
        if buf.is_empty() {
            None
        } else {
            Some(unsafe { String::from_utf8_unchecked(buf) })
        }
    }
}

pub struct Scanner<R: std::io::Read> {
    tokenizer: Tokenizer<R>,
}

impl<R: std::io::Read> Scanner<R> {
    pub fn new(r: R) -> Scanner<R> {
        Scanner {
            tokenizer: Tokenizer::new(r),
        }
    }
}

pub trait FromTokens {
    fn from_tokens(tokens: &mut Iterator<Item = String>) -> Self;
}

macro_rules! from_tokens_primitives {
    ($($t:ty),*) => { $(
        impl FromTokens for $t {
            fn from_tokens(tokens: &mut Iterator<Item = String>) -> Self {
                tokens
                    .next()
                    .expect("no more token")
                    .parse()
                    .ok()
                    .expect("Parse error")
            }
        }
    )* }
}

// FIXME: Can it be implemented by FromStr?
from_tokens_primitives! {
    String,
    bool,
    f32,
    f64,
    isize,
    i8,
    i16,
    i32,
    i64,
    usize,
    u8,
    u16,
    u32,
    u64
}

impl<T1: FromTokens, T2: FromTokens> FromTokens for (T1, T2) {
    fn from_tokens(tokens: &mut Iterator<Item = String>) -> Self {
        (T1::from_tokens(tokens), T2::from_tokens(tokens))
    }
}

impl<T1: FromTokens, T2: FromTokens, T3: FromTokens> FromTokens for (T1, T2, T3) {
    fn from_tokens(tokens: &mut Iterator<Item = String>) -> Self {
        (
            T1::from_tokens(tokens),
            T2::from_tokens(tokens),
            T3::from_tokens(tokens),
        )
    }
}

impl<T1: FromTokens, T2: FromTokens, T3: FromTokens, T4: FromTokens> FromTokens
    for (T1, T2, T3, T4)
{
    fn from_tokens(tokens: &mut Iterator<Item = String>) -> Self {
        (
            T1::from_tokens(tokens),
            T2::from_tokens(tokens),
            T3::from_tokens(tokens),
            T4::from_tokens(tokens),
        )
    }
}

impl<T1: FromTokens, T2: FromTokens, T3: FromTokens, T4: FromTokens, T5: FromTokens> FromTokens
    for (T1, T2, T3, T4, T5)
{
    fn from_tokens(tokens: &mut Iterator<Item = String>) -> Self {
        (
            T1::from_tokens(tokens),
            T2::from_tokens(tokens),
            T3::from_tokens(tokens),
            T4::from_tokens(tokens),
            T5::from_tokens(tokens),
        )
    }
}

impl<R: std::io::Read> Scanner<R> {
    pub fn read<T: FromTokens>(&mut self) -> T {
        T::from_tokens(&mut self.tokenizer)
    }

    pub fn read_vec<T: FromTokens>(&mut self, n: usize) -> Vec<T> {
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

// See https://docs.rs/superslice/1.0.0/superslice/trait.Ext.html
pub trait SliceExt {
    type Item;

    fn lower_bound(&self, x: &Self::Item) -> usize
    where
        Self::Item: Ord;

    fn lower_bound_by<'a, F>(&'a self, f: F) -> usize
    where
        F: FnMut(&'a Self::Item) -> Ordering;

    fn lower_bound_by_key<'a, K, F>(&'a self, k: &K, f: F) -> usize
    where
        F: FnMut(&'a Self::Item) -> K,
        K: Ord;

    fn upper_bound(&self, x: &Self::Item) -> usize
    where
        Self::Item: Ord;

    fn upper_bound_by<'a, F>(&'a self, f: F) -> usize
    where
        F: FnMut(&'a Self::Item) -> Ordering;

    fn upper_bound_by_key<'a, K, F>(&'a self, k: &K, f: F) -> usize
    where
        F: FnMut(&'a Self::Item) -> K,
        K: Ord;
}

impl<T> SliceExt for [T] {
    type Item = T;

    fn lower_bound(&self, x: &Self::Item) -> usize
    where
        T: Ord,
    {
        self.lower_bound_by(|y| y.cmp(x))
    }

    fn lower_bound_by<'a, F>(&'a self, mut f: F) -> usize
    where
        F: FnMut(&'a Self::Item) -> Ordering,
    {
        let s = self;
        let mut size = s.len();
        if size == 0 {
            return 0;
        }
        let mut base = 0usize;
        while size > 1 {
            let half = size / 2;
            let mid = base + half;
            let cmp = f(unsafe { s.get_unchecked(mid) });
            base = if cmp == Less { mid } else { base };
            size -= half;
        }
        let cmp = f(unsafe { s.get_unchecked(base) });
        base + (cmp == Less) as usize
    }

    fn lower_bound_by_key<'a, K, F>(&'a self, k: &K, mut f: F) -> usize
    where
        F: FnMut(&'a Self::Item) -> K,
        K: Ord,
    {
        self.lower_bound_by(|e| f(e).cmp(k))
    }

    fn upper_bound(&self, x: &Self::Item) -> usize
    where
        T: Ord,
    {
        self.upper_bound_by(|y| y.cmp(x))
    }

    fn upper_bound_by<'a, F>(&'a self, mut f: F) -> usize
    where
        F: FnMut(&'a Self::Item) -> Ordering,
    {
        let s = self;
        let mut size = s.len();
        if size == 0 {
            return 0;
        }
        let mut base = 0usize;
        while size > 1 {
            let half = size / 2;
            let mid = base + half;
            let cmp = f(unsafe { s.get_unchecked(mid) });
            base = if cmp == Greater { base } else { mid };
            size -= half;
        }
        let cmp = f(unsafe { s.get_unchecked(base) });
        base + (cmp != Greater) as usize
    }

    fn upper_bound_by_key<'a, K, F>(&'a self, k: &K, mut f: F) -> usize
    where
        F: FnMut(&'a Self::Item) -> K,
        K: Ord,
    {
        self.upper_bound_by(|e| f(e).cmp(k))
    }
}

//}}}