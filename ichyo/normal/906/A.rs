fn main() {
    let n: usize = readln();
    let mut st = HashSet::new();
    for c in 0..26 {
        let c = ('a' as u8 + c) as char;
        st.insert(c);
    }
    let mut ans = 0;
    for _ in 0..n {
        let (c, s): (String, String) = readln();
        let c = c.chars().next().unwrap();
        match c {
            '!' => {
                if st.len() == 1 {
                    ans += 1;
                }
                st = st.into_iter().filter(|&c| s.contains(c)).collect();
            },
            '.' => {
                st = st.into_iter().filter(|&c| !s.contains(c)).collect();
            },
            '?' => {
                let s = s.chars().next().unwrap();
                if st.len() == 1 && s == *st.iter().next().unwrap() {
                    // should be last
                } else {
                    if st.len() == 1 {
                        ans += 1;
                    }
                    st = st.into_iter().filter(|&c| s != c).collect();
                }
            },
            _ => unreachable!(),
        }
    }
    println!("{}", ans);
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
    for _ in 0..n { vs.push(readln()); }
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
fromln_primitives!(String, bool, f32, f64, isize, i8, i16, i32, i64, usize, u8, u16, u32, u64);
impl<T> FromLn for Vec<T> where T: FromLn {
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