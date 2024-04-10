fn possible(score: usize, total: usize, pairs: &[(usize, usize)]) -> Option<Vec<usize>> {
    let mut times: Vec<_> = pairs
        .iter()
        .enumerate()
        .filter(|&(_, &(a, _))| score <= a)
        .map(|(idx, &(_, t))| (t, idx))
        .collect();
    if times.len() < score {
        return None;
    }
    times.sort();
    let need: usize = times.iter().map(|&(t, _)| t).take(score).sum();
    if need <= total {
        Some(times.iter().map(|&(_, idx)| idx + 1).take(score).collect())
    } else {
        None
    }
}
fn main() {
    let (n, t) = readln();
    let vs = readlns(n);
    let mut lb = 0;
    let mut ub = n + 1;
    // [lb, ub)
    while ub - lb > 1 {
        let mid = (lb + ub) / 2;
        if let Some(_) = possible(mid, t, &vs) {
            lb = mid;
        } else {
            ub = mid;
        }
    }
    let score = lb;
    let res = possible(score, t, &vs).unwrap();
    println!("{}", score);
    println!("{}", res.len());
    println!(
        "{}",
        res.iter()
            .map(|x| x.to_string())
            .collect::<Vec<_>>()
            .join(" ")
    );
}

// --- template ---
#[allow(unused_imports)]
use std::cmp::{max, min};
#[allow(unused_imports)]
use std::collections::HashSet;

pub trait FromLn {
    fn fromln(s: &str) -> Self;
}
pub fn readln<T: FromLn>() -> T {
    let mut buf = String::new();
    let _ = ::std::io::stdin().read_line(&mut buf).unwrap();
    T::fromln(buf.trim())
}
pub fn readlns<T: FromLn>(n: usize) -> Vec<T> {
    let mut vs = vec![];
    for _ in 0..n {
        vs.push(readln());
    }
    vs
}
macro_rules! fromln_primitives {
    ($($t:ty),*) => { $(
        impl FromLn for $t {
            fn fromln(s: &str) -> $t {
                s.parse().unwrap()
            }
        }
    )* }
}
fromln_primitives!(
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
);
impl<T> FromLn for Vec<T>
where
    T: FromLn,
{
    fn fromln(s: &str) -> Vec<T> {
        s.split_whitespace().map(T::fromln).collect()
    }
}
impl FromLn for Vec<char> {
    fn fromln(s: &str) -> Vec<char> {
        s.chars().collect()
    }
}
macro_rules! fromln_tuple {
    ($($t:ident),*) => {
        impl<$($t),*> FromLn for ($($t),*) where $($t: FromLn),* {
            fn fromln(s: &str) -> ($($t),*) {
                let mut it = s.split_whitespace();
                let t = ($($t::fromln(it.next().unwrap())),*);
                assert_eq!(it.next(), None);
                t
            }
        }
    }
}
fromln_tuple!(A, B);
fromln_tuple!(A, B, C);
fromln_tuple!(A, B, C, D);
fromln_tuple!(A, B, C, D, E);
fromln_tuple!(A, B, C, D, E, F);