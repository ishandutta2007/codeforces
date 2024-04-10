fn main() {
    let ans = r#"!x&x
!(x|y|z)
!x&!y&z
!x&!y
!x&!z&y
!x&!z
!(!y&!z|x|y&z)
!(x|y&z)
!x&y&z
!(!y&z|!z&y|x)
!x&z
!(!z&y|x)
!x&y
!(!y&z|x)
!x&(y|z)
!x
!y&!z&x
!y&!z
!(!x&!z|x&z|y)
!(x&z|y)
!(!x&!y|x&y|z)
!(x&y|z)
!(!x&!y|x&y|z)|!x&!y&z
!((x|y)&z|x&y)
!x&y&z|!y&!z&x
!x&y&z|!y&!z
!x&z|!y&!z&x
!x&z|!y&!z
!x&y|!y&!z&x
!x&y|!y&!z
!x&(y|z)|!y&!z&x
!x|!y&!z
!y&x&z
!(!x&z|!z&x|y)
!y&z
!(!z&x|y)
!x&!z&y|!y&x&z
!x&!z|!y&x&z
!x&!z&y|!y&z
!x&!z|!y&z
!x&y&z|!y&x&z
!(!x&z|!z&x|y)|!x&y&z
!(x&y)&z
!(!z&x|y)|!x&z
!x&y|!y&x&z
!(!y&z|x)|!y&x&z
!x&y|!y&z
!x|!y&z
!y&x
!(!x&z|y)
!y&(x|z)
!y
!x&!z&y|!y&x
!x&!z|!y&x
!x&!z&y|!y&(x|z)
!x&!z|!y
!x&y&z|!y&x
!(!x&z|y)|!x&y&z
!x&z|!y&x
!x&z|!y
!x&y|!y&x
!(!x&!y&z|x&y)
!x&(y|z)|!y&x
!x|!y
!z&x&y
!(!x&y|!y&x|z)
!x&!y&z|!z&x&y
!x&!y|!z&x&y
!z&y
!(!y&x|z)
!x&!y&z|!z&y
!x&!y|!z&y
!x&y&z|!z&x&y
!(!x&y|!y&x|z)|!x&y&z
!x&z|!z&x&y
!(!z&y|x)|!z&x&y
!(x&z)&y
!(!y&x|z)|!x&y
!x&z|!z&y
!x|!z&y
!z&x
!(!x&y|z)
!x&!y&z|!z&x
!x&!y|!z&x
!z&(x|y)
!z
!x&!y&z|!z&(x|y)
!x&!y|!z
!x&y&z|!z&x
!(!x&y|z)|!x&y&z
!x&z|!z&x
!(!x&!z&y|x&z)
!x&y|!z&x
!x&y|!z
!x&(y|z)|!z&x
!x|!z
!y&x&z|!z&x&y
!(!x&y|!y&x|z)|!y&x&z
!y&z|!z&x&y
!(!z&x|y)|!z&x&y
!y&x&z|!z&y
!(!y&x|z)|!y&x&z
!y&z|!z&y
!(!y&!z&x|y&z)
!x&y&z|!y&x&z|!z&x&y
!(!x&y|!y&x|z)|!x&y&z|!y&x&z
!(x&y)&z|!z&x&y
!(!z&x|y)|!x&z|!z&x&y
!(x&z)&y|!y&x&z
!(!y&x|z)|!x&y|!y&x&z
!(x&y)&z|!z&y
!x|!y&z|!z&y
!(y&z)&x
!(!x&y|z)|!y&x
!y&z|!z&x
!y|!z&x
!y&x|!z&y
!y&x|!z
!y&(x|z)|!z&y
!y|!z
!(y&z)&x|!x&y&z
!(!x&y|z)|!x&y&z|!y&x
!(x&y)&z|!z&x
!x&z|!y|!z&x
!(x&z)&y|!y&x
!x&y|!y&x|!z
!x&y|!y&z|!z&x
!(x&y&z)
x&y&z
!(x|y|z)|x&y&z
!x&!y&z|x&y&z
!x&!y|x&y&z
!x&!z&y|x&y&z
!x&!z|x&y&z
!(!y&!z|x|y&z)|x&y&z
!(x|y&z)|x&y&z
y&z
!(x|y|z)|y&z
!x&z|y&z
!x&!y|y&z
!x&y|y&z
!x&!z|y&z
!x&(y|z)|y&z
!x|y&z
!y&!z&x|x&y&z
!y&!z|x&y&z
!(!x&!z|x&z|y)|x&y&z
!(x&z|y)|x&y&z
!(!x&!y|x&y|z)|x&y&z
!(x&y|z)|x&y&z
!(!x&!y|x&y|z)|!x&!y&z|x&y&z
!((x|y)&z|x&y)|x&y&z
!y&!z&x|y&z
!y&!z|y&z
!x&z|!y&!z&x|y&z
!(x&z|y)|y&z
!x&y|!y&!z&x|y&z
!(x&y|z)|y&z
!x&(y|z)|!y&!z&x|y&z
!x|!y&!z|y&z
x&z
!(x|y|z)|x&z
!y&z|x&z
!x&!y|x&z
!x&!z&y|x&z
!x&!z|x&z
!x&!z&y|!y&z|x&z
!(x|y&z)|x&z
(x|y)&z
!(x|y|z)|(x|y)&z
z
!x&!y|z
!x&y|x&z
!(!y&z|x)|x&z
!x&y|z
!x|z
!y&x|x&z
!y&!z|x&z
!y&(x|z)|x&z
!y|x&z
!x&!z&y|!y&x|x&z
!(x&y|z)|x&z
!x&!z&y|!y&(x|z)|x&z
!x&!z|!y|x&z
!y&x|y&z
!(!x&z|y)|y&z
!y&x|z
!y|z
!x&y|!y&x|x&z
!x&!z|!y&x|y&z
!x&y|!y&x|z
!x|!y|z
x&y
!(x|y|z)|x&y
!x&!y&z|x&y
!x&!y|x&y
!z&y|x&y
!x&!z|x&y
!x&!y&z|!z&y|x&y
!(x|y&z)|x&y
(x|z)&y
!(x|y|z)|(x|z)&y
!x&z|x&y
!(!z&y|x)|x&y
y
!x&!z|y
!x&z|y
!x|y
!z&x|x&y
!y&!z|x&y
!x&!y&z|!z&x|x&y
!(x&z|y)|x&y
!z&(x|y)|x&y
!z|x&y
!x&!y&z|!z&(x|y)|x&y
!x&!y|!z|x&y
!z&x|y&z
!(!x&y|z)|y&z
!x&z|!z&x|x&y
!x&!y|!z&x|y&z
!z&x|y
!z|y
!x&z|!z&x|y
!x|!z|y
(y|z)&x
!(x|y|z)|(y|z)&x
!y&z|x&y
!(!z&x|y)|x&y
!z&y|x&z
!(!y&x|z)|x&z
!y&z|!z&y|x&y
!x&!y|!z&y|x&z
(x|y)&z|x&y
!(x|y|z)|(x|y)&z|x&y
x&y|z
!x&!y|x&y|z
x&z|y
!x&!z|x&z|y
y|z
!x|y|z
x
!y&!z|x
!y&z|x
!y|x
!z&y|x
!z|x
!y&z|!z&y|x
!y|!z|x
x|y&z
!y&!z|x|y&z
x|z
!y|x|z
x|y
!z|x|y
x|y|z
!x|x"#;
    let answers: Vec<&str> = ans.lines().collect();
    let n = readln();
    for _ in 0..n {
        let s: String = readln();
        let s = s.as_bytes();
        let mut x = 0;
        for i in 0..8 {
            x += if s[i] == b'1' { 1 << i } else { 0 }
        }
        println!("{}", answers[x]);
    }
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