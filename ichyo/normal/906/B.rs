fn next_permutation<T: std::cmp::Ord>(array: &mut [T]) -> bool {
	// Find non-increasing suffix
	if array.is_empty() {
		return false;
	}
	let mut i: usize = array.len() - 1;
	while i > 0 && array[i - 1] >= array[i] {
		i -= 1;
	}
	if i == 0 {
		return false;
	}
	
	// Find successor to pivot
	let mut j: usize = array.len() - 1;
	while array[j] <= array[i - 1] {
		j -= 1;
	}
	array.swap(i - 1, j);
	
	// Reverse suffix
	array[i .. ].reverse();
	true
}

fn to_idx(x: usize, y: usize, m: usize) -> usize {
    x + y * m
}
fn to_xy(idx: usize, m: usize) -> (usize, usize) {
    (idx % m, idx / m)
}

fn check(order: &[usize], n: usize, m: usize) -> Option<(usize, usize)> {
    let dx = [0, 1, 0, -1];
    let dy = [1, 0, -1, 0];
    for y in 0..n {
        for x in 0..m {
            for r in 0..4 {
                let nx = (x as i32 + dx[r]);
                let ny = (y as i32 + dy[r]);
                if nx >= 0 && nx < m as i32 && ny >= 0 && ny < n as i32 {
                    let nx = nx as usize;
                    let ny = ny as usize;
                    let a = order[to_idx(x, y, m)];
                    let b = order[to_idx(nx, ny, m)];
                    let (ax, ay) = to_xy(a, m);
                    let (bx, by) = to_xy(b, m);
                    if ax == bx && (ay as i32 - by as i32).abs() == 1 {
                        return Some((x, y));
                    }
                    if ay == by && (ax as i32 - bx as i32).abs() == 1 {
                        return Some((x, y));
                    }
                }
            }
        }
    }
    None
}

fn print(order: &[usize], n: usize, m: usize) {
    for y in 0..n {
        for x in 0..m {
            print!("{} ", order[y*m+x]+1);
        }
        println!("");
    }
}

fn solve(n: usize, m: usize) -> Option<Vec<usize>> {
    let size = n * m;
    let mut order: Vec<_> = (0..size).collect();
    if size <= 10 {
        loop {
            if check(order.as_mut_slice(), n, m).is_none() {
                return Some(order);
            }
            if !next_permutation(order.as_mut_slice()) {
                break;
            }
        }
        None
    } else {
        let mut seed: usize = 0x123456;
        let mut next = || {
            seed = seed.wrapping_mul(0x12345678deadc0d1).wrapping_add(0x1551);
            seed
        };
        let mut tmp: Vec<_> = order.iter().map(|x| (next(), x)).collect();
        tmp.sort();
        let mut order: Vec<_> = tmp.iter().map(|&(_, x)| *x).collect();
        while let Some((x, y)) = check(order.as_mut_slice(), n, m) {
            let ny = next() % n;
            let nx = next() % m;
            order.swap(to_idx(x, y, m), to_idx(nx, ny, m));
        }
        Some(order)
    }
}

fn main() {
    let (n, m) = readln();
    let ans = solve(n, m);
    match ans {
        Some(ans) => {
            println!("YES");
            print(&ans, n, m);
        },
        None => {
            println!("NO");
        }
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