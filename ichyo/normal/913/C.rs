fn main() {
    let (n, l): (usize, i64) = readln();
    let c: Vec<i64> = readln();

    let mut rest: i64 = l;
    let mut answer = i64::max_value();
    let mut used: i64 = 0;
    while rest > 0 {
        let over_cost = (0..n).filter(|x| rest <= (1i64 << x)).map(|x| c[x]).min();
        if let Some(over_cost) = over_cost {
            answer = min(answer, used + over_cost);
        }
        let last_idx = (0..n).filter(|x| rest >= (1i64 << x)).last().unwrap();
        let cost = (0..last_idx + 1)
            .map(|x| (1i64 << (last_idx - x)) * c[x])
            .min()
            .unwrap();
        let last_pow = (0..36).filter(|x| rest >= (1i64 << x)).last().unwrap();
        used += cost * 1i64 << (last_pow - last_idx);
        rest -= 1i64 << last_pow;
    }
    answer = min(answer, used);
    println!("{}", answer);
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