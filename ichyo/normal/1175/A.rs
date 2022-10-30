// See run() at line 135 for solution.
#![allow(unused_imports, unused_macros, non_snake_case)]
use std::cmp::{max, min, Ordering};
use std::collections::{BTreeMap, BTreeSet, BinaryHeap, HashMap, HashSet, VecDeque};

//{{{ ---- macros ----
#[macro_use]
mod macros {
    // {{{ input!
    // https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8
    macro_rules! input {
        (source = $s:expr, $($r:tt)*) => {
            let mut iter = $s.split_whitespace();
            let mut next = || { iter.next().unwrap() };
            input_inner!{next, $($r)*}
        };
        ($($r:tt)*) => {
            let stdin = std::io::stdin();
            let mut bytes = std::io::Read::bytes(std::io::BufReader::new(stdin.lock()));
            let mut next = move || -> String{
                bytes
                    .by_ref()
                    .map(|r|r.unwrap() as char)
                    .skip_while(|c|c.is_whitespace())
                    .take_while(|c|!c.is_whitespace())
                    .collect()
            };
            input_inner!{next, $($r)*}
        };
    }
    macro_rules! input_inner {
        ($next:expr) => {};
        ($next:expr, ) => {};

        ($next:expr, $var:ident : $t:tt $($r:tt)*) => {
            let $var = read_value!($next, $t);
            input_inner!{$next $($r)*}
        };
    }
    macro_rules! read_value {
        ($next:expr, ( $($t:tt),* )) => {
            ( $(read_value!($next, $t)),* )
        };

        ($next:expr, [ $t:tt ; $len:expr ]) => {
            (0..$len).map(|_| read_value!($next, $t)).collect::<Vec<_>>()
        };

        ($next:expr, chars) => {
            read_value!($next, String).chars().collect::<Vec<char>>()
        };

        ($next:expr, usize1) => {
            read_value!($next, usize) - 1
        };

        ($next:expr, $t:ty) => {
            $next().parse::<$t>().expect("Parse error")
        };
    }
    //}}}

    //{{{ read!
    macro_rules! read {
        ($($t:tt),*; $n:expr) => {{
            let stdin = ::std::io::stdin();
            let ret = ::std::io::BufRead::lines(stdin.lock()).take($n).map(|line| {
                let line = line.unwrap();
                let mut it = line.split_whitespace();
                _read!(it; $($t),*)
            }).collect::<Vec<_>>();
            ret
        }};
        ($($t:tt),*) => {{
            let line = readln();
            let mut it = line.split_whitespace();
            _read!(it; $($t),*)
        }};
    }

    macro_rules! _read {
        ($it:ident; [char]) => {
            _read!($it; String).chars().collect::<Vec<_>>()
        };
        ($it:ident; [u8]) => {
            Vec::from(_read!($it; String).into_bytes())
        };
        ($it:ident; [$t:ty]) => {
            $it.map(|s| s.parse::<$t>().unwrap_or_else(|e| panic!("{}", e))).collect::<Vec<_>>()
        };
        ($it:ident; $t:ty) => {
            $it.next().unwrap_or_else(|| panic!("input mismatch")).parse::<$t>().unwrap_or_else(|e| panic!("{}", e))
        };
        ($it:ident; $($t:ty),+) => {
            ($(_read!($it; $t)),*)
        };
    }
    //}}}

    //{{{ utility macros missing in 1.15.1
    // https://atcoder.jp/contests/nikkei2019-qual/submissions/4098548
    macro_rules! eprint {
        ($($t:tt)*) => {{
            use ::std::io::Write;
            let _ = write!(::std::io::stderr(), $($t)*);
        }};
    }
    macro_rules! eprintln {
        () => { eprintln!(""); };
        ($($t:tt)*) => {{
            use ::std::io::Write;
            let _ = writeln!(::std::io::stderr(), $($t)*);
        }};
    }
    macro_rules! dbg {
        ($val:expr) => {
            match $val {
                tmp => {
                    eprintln!(
                        "[{}:{}] {} = {:#?}",
                        file!(),
                        line!(),
                        stringify!($val),
                        &tmp
                    );
                    tmp
                }
            }
        };
    }
    //}}}
}
//}}}

fn run() {
    let t = read!(usize);
    for _ in 0..t {
        let (mut n, k) = read!(u64, u64);
        let mut answer = 0;
        while n > 0 {
            if n % k == 0 {
                answer += 1;
                n /= k;
            } else {
                answer += n % k;
                n -= n % k;
            }
        }
        println!("{}", answer);
    }
}

//{{{ ---- template ----
fn main() {
    let _ = ::std::thread::Builder::new()
        .name("run".to_string())
        .stack_size(256 * 1024 * 1024)
        .spawn(run)
        .unwrap()
        .join()
        .unwrap();
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

#[allow(unused)] // This is defined for read! macro
fn readln() -> String {
    let mut line = String::new();
    ::std::io::stdin()
        .read_line(&mut line)
        .unwrap_or_else(|e| panic!("{}", e));
    line
}
//}}}

//{{{ https://github.com/ichyo/rust-algorithms.git
pub mod algonium {
    #![doc = " This library provides a collection of classic algorithms,"]
    #![doc = " focusing on programming contests such as codeforces and atcoder."]
    pub mod data_structure {
        mod bit {
            #[doc = " Binary Indexed Tree (0-indexed)"]
            #[doc = ""]
            #[doc = " This data structure supports these two queries in O(log n)"]
            #[doc = ""]
            #[doc = " 1. add w to v[at]"]
            #[doc = " 2. the sum of v[begin], v[begin+1], .., v[end-1]"]
            pub struct BIT {
                tree: Vec<i64>,
            }
            #[doc = " Binary Indexed Tree (range-version) (0-indexed)"]
            #[doc = ""]
            #[doc = " This data structure two queries in O(log n)"]
            #[doc = ""]
            #[doc = " 1. add w to v[begin], v[begin+1], ..., v[end-1]"]
            #[doc = " 2. get the sum of v[begin], v[begin+1], ..., v[end-1]"]
            pub struct BITRange {
                bit0: BIT,
                bit1: BIT,
            }
            impl BIT {
                #[doc = " Constructs a new BIT of length `len`."]
                #[doc = " All values are initialized zero."]
                #[doc = ""]
                #[doc = " # Examples"]
                #[doc = " ```"]
                #[doc = " use algonium::data_structure::BIT;"]
                #[doc = " # #[warn(unused_mut)]"]
                #[doc = " let mut bit = BIT::new(100);"]
                #[doc = " ```"]
                pub fn new(len: usize) -> BIT {
                    BIT { tree: vec![0; len] }
                }
                #[doc = " Returns the number of elements in the BIT."]
                #[doc = ""]
                #[doc = " # Examples"]
                #[doc = ""]
                #[doc = " ```"]
                #[doc = " use algonium::data_structure::BIT;"]
                #[doc = " let mut bit = BIT::new(100);"]
                #[doc = " assert_eq!(bit.len(), 100);"]
                #[doc = " ```"]
                pub fn len(&self) -> usize {
                    self.tree.len()
                }
                #[doc = " Add a value `value` to a element of index `index`."]
                #[doc = " v[index] += value"]
                #[doc = ""]
                #[doc = " # Panics"]
                #[doc = ""]
                #[doc = " Panics if `index > len`"]
                #[doc = ""]
                #[doc = " # Examples"]
                #[doc = ""]
                #[doc = " ```"]
                #[doc = " use algonium::data_structure::BIT;"]
                #[doc = " let mut bit = BIT::new(10);"]
                #[doc = " bit.add(5, 100);"]
                #[doc = " assert_eq!(bit.get(3, 6), 100);"]
                #[doc = " bit.add(5, 10);"]
                #[doc = " assert_eq!(bit.get(3, 6), 110);"]
                #[doc = " ```"]
                pub fn add(&mut self, index: usize, value: i64) {
                    assert!(index < self.tree.len());
                    let mut idx = index;
                    while idx < self.tree.len() {
                        self.tree[idx] += value;
                        idx |= idx + 1;
                    }
                }
                #[doc = " sum of v[idx] such that begin <= idx < end"]
                pub fn get(&self, begin: usize, end: usize) -> i64 {
                    if begin >= end {
                        return 0;
                    }
                    let a = if end > 0 { self.cum(end - 1) } else { 0 };
                    let b = if begin > 0 { self.cum(begin - 1) } else { 0 };
                    a - b
                }
                #[doc = " v[0] + ... + v[last]"]
                fn cum(&self, last: usize) -> i64 {
                    assert!(last < self.tree.len());
                    let mut res = 0;
                    let mut idx = last as i64;
                    while idx >= 0 {
                        res += self.tree[idx as usize];
                        idx = (idx & (idx + 1)) - 1;
                    }
                    res
                }
            }
            impl BITRange {
                pub fn new(n: usize) -> BITRange {
                    BITRange {
                        bit0: BIT::new(n + 1),
                        bit1: BIT::new(n + 1),
                    }
                }
                #[doc = " v[begin], v[begin+1], ..., v[end-1] += by"]
                pub fn add(&mut self, begin: usize, end: usize, by: i64) {
                    if begin >= end {
                        return;
                    }
                    let a = begin as i64;
                    let b = end as i64;
                    self.bit0.add(begin, -by * a);
                    self.bit0.add(end, by * b);
                    self.bit1.add(begin, by);
                    self.bit1.add(end, -by);
                }
                #[doc = " v[begin] + ... + v[end-1]"]
                pub fn get(&self, begin: usize, end: usize) -> i64 {
                    if begin >= end {
                        return 0;
                    }
                    self.cum(end) - self.cum(begin)
                }
                #[doc = " v[0] + ... + v[end-1]"]
                fn cum(&self, end: usize) -> i64 {
                    let a = self.bit0.get(0, end);
                    let b = self.bit1.get(0, end);
                    a + b * end as i64
                }
            }
            #[cfg(test)]
            mod tests {
                use super::*;
                #[test]
                #[should_panic]
                fn test_out_of_bound_add() {
                    let mut bit = BIT::new(10);
                    bit.add(100, 1);
                }
                #[test]
                #[should_panic]
                fn test_out_of_bound_range_add() {
                    let mut bit = BITRange::new(10);
                    bit.add(5, 100, 1);
                }
                #[test]
                #[should_panic]
                fn test_out_of_bound_get() {
                    let bit = BIT::new(10);
                    bit.get(0, 1000);
                }
                #[test]
                fn test_empty_range() {
                    let mut bit = BITRange::new(10);
                    bit.add(9, 0, 100);
                    bit.add(7, 3, 100);
                    assert_eq!(0, bit.get(0, 9));
                    assert_eq!(0, bit.get(0, 5));
                    assert_eq!(0, bit.get(2, 5));
                }
                #[test]
                fn test_simple() {
                    let mut bit = BIT::new(10);
                    bit.add(2, 1);
                    bit.add(3, 3);
                    bit.add(5, 10);
                    bit.add(0, -4);
                    bit.add(9, -5);
                    assert_eq!(5, bit.get(0, 10));
                    assert_eq!(4, bit.get(2, 4));
                    assert_eq!(1, bit.get(2, 3));
                    assert_eq!(0, bit.get(2, 2));
                    assert_eq!(0, bit.get(2, 0));
                    assert_eq!(-4, bit.get(0, 1));
                    assert_eq!(5, bit.get(5, 10));
                    let mut bit = BITRange::new(10);
                    bit.add(1, 3, 1);
                    bit.add(2, 5, 2);
                    assert_eq!(1, bit.get(1, 2));
                    assert_eq!(4, bit.get(1, 3));
                    assert_eq!(6, bit.get(1, 4));
                    assert_eq!(6, bit.get(0, 4));
                }
            }
        }
        mod segment_tree {
            use std::cmp;
            use std::marker::PhantomData;
            pub trait Monoid<T> {
                fn id() -> Option<T> {
                    None
                }
                fn op(l: &Option<T>, r: &Option<T>) -> Option<T>;
            }
            pub struct MinOp<T: Ord> {
                phantom: PhantomData<T>,
            }
            impl<T: Ord + Clone> Monoid<T> for MinOp<T> {
                #[inline]
                fn op(l: &Option<T>, r: &Option<T>) -> Option<T> {
                    match (l.clone(), r.clone()) {
                        (Some(l), Some(r)) => Some(cmp::min(l, r)),
                        (Some(l), None) => Some(l),
                        (None, Some(r)) => Some(r),
                        (None, None) => None,
                    }
                }
            }
            pub struct SegmentTree<M: Monoid<T>, T: Clone> {
                phantom: PhantomData<M>,
                data: Vec<Option<T>>,
                size: usize,
                size_p2: usize,
            }
            impl<M: Monoid<T>, T: Clone> SegmentTree<M, T> {
                pub fn from_vec(v: Vec<T>) -> SegmentTree<M, T> {
                    let size = v.len();
                    let mut size_p2 = 1;
                    while size_p2 < v.len() {
                        size_p2 *= 2;
                    }
                    let mut data = vec![None; size_p2 * 2];
                    for (i, x) in v.into_iter().enumerate() {
                        data[size_p2 + i] = Some(x);
                    }
                    for i in (0..size_p2).rev() {
                        data[i] = M::op(&data[i * 2 + 0], &data[i * 2 + 1]);
                    }
                    SegmentTree {
                        phantom: PhantomData,
                        data: data,
                        size: size,
                        size_p2: size_p2,
                    }
                }
                pub fn size(&self) -> usize {
                    self.size
                }
                pub fn update(&mut self, mut pos: usize, value: T) {
                    assert!(pos < self.size);
                    pos += self.size_p2;
                    self.data[pos] = Some(value);
                    loop {
                        pos /= 2;
                        if pos == 0 {
                            break;
                        }
                        self.data[pos] = M::op(&self.data[pos * 2], &self.data[pos * 2 + 1]);
                    }
                }
                pub fn query(&self, mut l: usize, mut r: usize) -> Option<T> {
                    assert!(l <= r && r <= self.size);
                    l += self.size_p2;
                    r += self.size_p2;
                    let mut res1 = M::id();
                    let mut res2 = M::id();
                    while l < r {
                        if (l & 1) != 0 {
                            res1 = M::op(&res1, &self.data[l]);
                            l += 1;
                        }
                        if (r & 1) != 0 {
                            r -= 1;
                            res2 = M::op(&self.data[r], &res2);
                        }
                        l >>= 1;
                        r >>= 1;
                    }
                    M::op(&res1, &res2)
                }
            }
            #[doc = " segment tree to get minimum value in a range"]
            pub type RMQ<T> = SegmentTree<MinOp<T>, T>;
            #[cfg(test)]
            mod tests {
                use super::RMQ;
                #[test]
                fn test_rms() {
                    let mut test = vec![1, 5, 4, 8, 6, 9, 2, 0, 8, 1];
                    let mut rms = RMQ::from_vec(test.clone());
                    for i in 0..test.len() {
                        for j in i..test.len() + 1 {
                            assert_eq!(test[i..j].iter().cloned().min(), rms.query(i, j));
                        }
                    }
                    rms.update(7, 5);
                    test[7] = 5;
                    for i in 0..test.len() {
                        for j in i..test.len() + 1 {
                            assert_eq!(test[i..j].iter().cloned().min(), rms.query(i, j));
                        }
                    }
                }
            }
        }
        mod union_find {
            #[doc = " Disjoint-set data structure"]
            #[doc = ""]
            #[doc = " This provides operations for disjoint sets."]
            #[doc = " They runs in nearly constatant time."]
            #[doc = " (the actual time is `O(A(n))` where `A(n)` is the inverse of ackermann function.)"]
            #[doc = ""]
            #[doc = " 1. unite(x, y) - unite a set including x and another set including y into one."]
            #[doc = " 2. same(x, y) - determine if x and y are in the same set."]
            #[doc = " 3. size(x) - calculate the number of elements of the set including x."]
            #[doc = ""]
            #[doc = " [`UnionFind::new(n)`](#method.new) creates n disjoint sets. `i`-th set contains single element `i` (0-indexed)."]
            #[doc = ""]
            #[doc = " # Examples"]
            #[doc = " ```"]
            #[doc = " use algonium::data_structure::UnionFind;"]
            #[doc = ""]
            #[doc = " let mut uf = UnionFind::new(4);"]
            #[doc = " assert!(!uf.same(0, 1));"]
            #[doc = ""]
            #[doc = " uf.unite(0, 1);"]
            #[doc = " assert!(uf.same(0, 1));"]
            #[doc = " assert_eq!(uf.size(0), 2);"]
            #[doc = ""]
            #[doc = " uf.unite(1, 2);"]
            #[doc = " assert!(uf.same(0, 2));"]
            #[doc = " assert_eq!(uf.size(0), 3);"]
            #[doc = " ```"]
            #[doc = ""]
            #[doc = " # Panics"]
            #[doc = " panics if `x` or `y` is not less than number of elements given in the initialization method."]
            #[doc = ""]
            pub struct UnionFind {
                data: Vec<i32>,
            }
            impl UnionFind {
                #[doc = " Creates a object with n disjoint sets. `i`-th set is `{ i }`."]
                pub fn new(n: usize) -> UnionFind {
                    UnionFind { data: vec![-1; n] }
                }
                #[doc = " Unite a set including `x` and another set including y into one."]
                #[doc = " Returns `true` only if they were in different set."]
                pub fn unite(&mut self, x: usize, y: usize) -> bool {
                    let x = self.root(x);
                    let y = self.root(y);
                    if x != y {
                        let (x, y) = if self.data[x] <= self.data[y] {
                            (x, y)
                        } else {
                            (y, x)
                        };
                        self.data[x] += self.data[y];
                        self.data[y] = x as i32;
                    }
                    x != y
                }
                #[doc = " Returns `true` only if `x` and `y` are in a same set."]
                pub fn same(&mut self, x: usize, y: usize) -> bool {
                    self.root(x) == self.root(y)
                }
                #[doc = " Returns the number of elements of a set including `x`."]
                pub fn size(&mut self, x: usize) -> u32 {
                    let r = self.root(x);
                    (-self.data[r]) as u32
                }
                #[doc = " internal method to return representative element of a set including `x`."]
                pub fn root(&mut self, x: usize) -> usize {
                    if self.data[x] < 0 {
                        x
                    } else {
                        let nx = self.data[x] as usize;
                        let r = self.root(nx);
                        self.data[x] = r as i32;
                        r
                    }
                }
            }
            #[cfg(test)]
            mod tests {
                use super::*;
                #[test]
                fn test_simple() {
                    let mut uf = UnionFind::new(3);
                    assert_eq!(1, uf.size(0));
                    assert_eq!(1, uf.size(1));
                    assert_eq!(1, uf.size(2));
                    assert_eq!(0, uf.root(0));
                    assert_eq!(1, uf.root(1));
                    assert_eq!(2, uf.root(2));
                    assert!(!uf.same(1, 2));
                    uf.unite(1, 2);
                    assert_ne!(uf.root(0), uf.root(2));
                    assert_eq!(uf.root(1), uf.root(2));
                    assert_eq!(1, uf.size(0));
                    assert_eq!(2, uf.size(1));
                    assert_eq!(2, uf.size(2));
                    assert!(uf.same(1, 2));
                    uf.unite(0, 1);
                    assert_eq!(uf.root(0), uf.root(2));
                    assert_eq!(uf.root(1), uf.root(2));
                    assert_eq!(3, uf.size(0));
                    assert_eq!(3, uf.size(1));
                    assert_eq!(3, uf.size(2));
                    assert!(uf.same(1, 2));
                    assert!(uf.same(0, 2));
                }
            }
        }
        pub use self::bit::{BITRange, BIT};
        pub use self::segment_tree::{MinOp, Monoid, SegmentTree, RMQ};
        pub use self::union_find::UnionFind;
    }
    pub mod math {
        mod comb {
            use super::mint::{Mint, Module};
            #[doc = " Useful struct to compute combinations"]
            #[doc = ""]
            #[doc = " # Examples"]
            #[doc = " ```"]
            #[doc = " use algonium::math::{Comb, Mod107, Mint107};"]
            #[doc = " let comb: Comb<Mod107> = Comb::new(100);"]
            #[doc = " assert_eq!(Mint107::from(24), comb.fact(4));"]
            #[doc = " assert_eq!(Mint107::from(1), comb.fact(4) * comb.factinv(4));"]
            #[doc = " assert_eq!(Mint107::from(12), comb.perm(4, 2));"]
            #[doc = " assert_eq!(Mint107::from(6), comb.comb(4, 2));"]
            #[doc = " assert_eq!(Mint107::from(10), comb.multi_comb(4, 2));"]
            #[doc = " ```"]
            pub struct Comb<M: Module> {
                fact: Vec<Mint<M>>,
                factinv: Vec<Mint<M>>,
            }
            impl<M: Module> Comb<M> {
                #[doc = " Create a object that provides effiecint computation of combinations"]
                #[doc = " for input smaller than `n`."]
                #[doc = ""]
                #[doc = " This requires `O(n)` time."]
                pub fn new(n: usize) -> Comb<M> {
                    let mut fact: Vec<Mint<M>> = vec![0.into(); n + 1];
                    let mut factinv: Vec<Mint<M>> = vec![0.into(); n + 1];
                    fact[0] = 1.into();
                    for i in 0..n {
                        fact[i + 1] = fact[i] * (i + 1);
                    }
                    factinv[n] = fact[n].inv();
                    for i in (0..n).rev() {
                        factinv[i] = factinv[i + 1] * (i + 1);
                    }
                    Comb {
                        fact: fact,
                        factinv: factinv,
                    }
                }
                #[doc = " `n! = 1 * 2 * ... * n`"]
                #[doc = ""]
                #[doc = " `O(1)` if n is smaller than input in `new` method."]
                pub fn fact(&self, n: u64) -> Mint<M> {
                    if let Some(x) = self.fact.get(n as usize) {
                        *x
                    } else if n >= M::module() as u64 {
                        Mint::from(0)
                    } else {
                        let mut res = 1.into();
                        for a in 1..(n + 1) {
                            res *= a;
                        }
                        res
                    }
                }
                #[doc = " returns `y` such that `n! * y == 1`."]
                #[doc = ""]
                #[doc = " `O(1)` if n is smaller than input in `new` method."]
                pub fn factinv(&self, n: u64) -> Mint<M> {
                    if let Some(x) = self.factinv.get(n as usize) {
                        *x
                    } else {
                        self.fact(n).inv()
                    }
                }
                #[doc = " `nPr = n! / (n - r)!`"]
                #[doc = ""]
                #[doc = " `O(1)` if n and r are smaller than input in `new` method."]
                pub fn perm(&self, n: u64, r: u64) -> Mint<M> {
                    if n >= r {
                        self.fact(n) * self.factinv((n - r) as u64)
                    } else {
                        0.into()
                    }
                }
                #[doc = " `nCr = n! / (n - r)! / r!`."]
                #[doc = ""]
                #[doc = " `O(1)` if n and r are smaller than input in `new` method."]
                pub fn comb(&self, n: u64, r: u64) -> Mint<M> {
                    let m = M::module() as u64;
                    if n >= m {
                        self.comb(n % m, r % m) * self.comb(n / m, r / m)
                    } else if n >= r {
                        self.fact(n) * self.factinv(n - r) * self.factinv(r)
                    } else {
                        Mint::from(0)
                    }
                }
                #[doc = " `(n + k - 1)! / k!`."]
                #[doc = ""]
                #[doc = " `O(1)` if n and r are smaller than input in `new` method."]
                pub fn multi_comb(&self, n: u64, r: u64) -> Mint<M> {
                    if r == 0 {
                        Mint::from(1)
                    } else {
                        self.comb(n + r - 1, r)
                    }
                }
            }
            #[cfg(test)]
            mod tests {
                use super::*;
                #[test]
                fn test_simple() {
                    #[derive(Clone, Copy, Debug)]
                    struct Mod;
                    impl Module for Mod {
                        fn module() -> u32 {
                            1000000007
                        }
                    }
                    let c = Comb::<Mod>::new(100);
                    assert_eq!(Mint::from(336), c.perm(8, 3));
                    assert_eq!(Mint::from(56), c.comb(8, 3));
                    assert_eq!(Mint::from(10), c.multi_comb(3, 3));
                }
                #[test]
                fn test_fact() {
                    #[derive(Clone, Copy, Debug)]
                    struct Mod;
                    impl Module for Mod {
                        fn module() -> u32 {
                            1000000007
                        }
                    }
                    let c = Comb::<Mod>::new(100);
                    let p = 8721234;
                    let mut f = Mint::from(1);
                    for i in 1..(p + 1) {
                        f *= i;
                    }
                    assert_eq!(f, c.fact(p));
                }
            }
        }
        mod mint {
            use std::fmt;
            use std::marker::PhantomData;
            use std::mem;
            use std::ops;
            #[doc = " Trait for `Mint`. `module()` should return prime number."]
            pub trait Module: Copy + Clone {
                fn module() -> u32;
            }
            #[doc = " One of famous numbers in programming contest. `10^9 + 7`"]
            pub const MOD_107: u32 = 1_000_000_007;
            #[doc = " One of famous numbers in programming contest. `10^9 + 9`"]
            pub const MOD_109: u32 = 1_000_000_009;
            #[doc = " One of famous numbers in programming contest. `998_244_353`"]
            pub const MOD_998: u32 = 998_244_353;
            #[doc = " struct to implement Module trait. it returns `MOD_107`."]
            #[derive(Debug, Copy, Clone)]
            pub struct Mod107;
            impl Module for Mod107 {
                fn module() -> u32 {
                    MOD_107
                }
            }
            #[doc = " struct to implement Module trait. it returns `MOD_109`."]
            #[derive(Debug, Copy, Clone)]
            pub struct Mod109;
            impl Module for Mod109 {
                fn module() -> u32 {
                    MOD_109
                }
            }
            #[doc = " struct to implement Module trait. it returns `MOD_998`."]
            #[derive(Debug, Copy, Clone)]
            pub struct Mod998;
            impl Module for Mod998 {
                fn module() -> u32 {
                    MOD_998
                }
            }
            #[doc = " Wrapper class to compute mod `1_000_000_007` automatically."]
            #[doc = ""]
            #[doc = " # Examples"]
            #[doc = " ```"]
            #[doc = " use algonium::math::{Mint107, MOD_107};"]
            #[doc = " let x: Mint107 = 1234567.into();"]
            #[doc = " let y: Mint107 = 2345678.into();"]
            #[doc = " let z = x * y;"]
            #[doc = " # // TODO: implement convert to u64"]
            #[doc = " assert_eq!(z.val as u64, 1234567u64 * 2345678u64 % MOD_107 as u64);"]
            #[doc = " ```"]
            #[doc = ""]
            pub type Mint107 = Mint<Mod107>;
            #[doc = " Wrapper class to compute mod `1_000_000_009` automatically."]
            #[doc = ""]
            #[doc = " # Examples"]
            #[doc = " ```"]
            #[doc = " use algonium::math::{Mint109, MOD_109};"]
            #[doc = " let x: Mint109 = 1234567.into();"]
            #[doc = " let y: Mint109 = 2345678.into();"]
            #[doc = " let z = x * y;"]
            #[doc = " assert_eq!(z.val as u64, 1234567u64 * 2345678u64 % MOD_109 as u64);"]
            #[doc = " ```"]
            #[doc = ""]
            pub type Mint109 = Mint<Mod109>;
            #[doc = " Wrapper class to compute mod `998_244_353` automatically."]
            #[doc = ""]
            #[doc = " # Examples"]
            #[doc = " ```"]
            #[doc = " use algonium::math::{Mint998, MOD_998};"]
            #[doc = " let x: Mint998 = 1234567.into();"]
            #[doc = " let y: Mint998 = 2345678.into();"]
            #[doc = " let z = x * y;"]
            #[doc = " assert_eq!(z.val as u64, 1234567u64 * 2345678u64 % MOD_998 as u64);"]
            #[doc = " ```"]
            #[doc = ""]
            pub type Mint998 = Mint<Mod998>;
            #[doc = " Wrapper class to compute modulo operation."]
            #[doc = " See examples"]
            #[doc = " [`Mint107`](type.Mint107.html),"]
            #[doc = " [`Mint109`](type.Mint109.html),"]
            #[doc = " [`Mint998`](type.Mint998.html)"]
            #[doc = ""]
            #[doc = " # Examples"]
            #[doc = " ```"]
            #[doc = " use algonium::math::{Mint107, MOD_107};"]
            #[doc = " let x: Mint107 = 1234567.into();"]
            #[doc = " let y: Mint107 = 2345678.into();"]
            #[doc = " let z = x * y;"]
            #[doc = " assert_eq!(z.val as u64, 1234567u64 * 2345678u64 % MOD_107 as u64);"]
            #[doc = " ```"]
            #[derive(Debug, Copy, Clone, Eq)]
            pub struct Mint<M: Module> {
                #[doc = " internal value. this is always less than `self.module()`."]
                pub val: u32,
                m: PhantomData<M>,
            }
            impl<M: Module> Mint<M> {
                fn module(self) -> u32 {
                    M::module()
                }
                fn new(val: u32) -> Mint<M> {
                    assert!(val < M::module());
                    Mint {
                        val: val,
                        m: PhantomData,
                    }
                }
            }
            impl<T: Into<Mint<M>>, M: Module> ops::Add<T> for Mint<M> {
                type Output = Mint<M>;
                fn add(self, other: T) -> Mint<M> {
                    let nval = self.val + other.into().val;
                    Mint::new(if nval >= self.module() {
                        nval - self.module()
                    } else {
                        nval
                    })
                }
            }
            impl<T: Into<Mint<M>>, M: Module> ops::Sub<T> for Mint<M> {
                type Output = Mint<M>;
                fn sub(self, other: T) -> Mint<M> {
                    let nval = self.val + self.module() - other.into().val;
                    Mint::new(if nval >= self.module() {
                        nval - self.module()
                    } else {
                        nval
                    })
                }
            }
            impl<T: Into<Mint<M>>, M: Module> ops::Mul<T> for Mint<M> {
                type Output = Mint<M>;
                fn mul(self, other: T) -> Mint<M> {
                    let nval = self.val as u64 * other.into().val as u64;
                    Mint::new((nval % (self.module() as u64)) as u32)
                }
            }
            impl<T: Into<Mint<M>>, M: Module> ops::Div<T> for Mint<M> {
                type Output = Mint<M>;
                fn div(self, other: T) -> Mint<M> {
                    self * other.into().inv()
                }
            }
            impl<M: Module> Mint<M> {
                #[doc = " Returns number `y` that satisfies `x * y == 1` where `x` is the original value."]
                #[doc = ""]
                #[doc = " This assumes `module()` returns prime number."]
                pub fn inv(self) -> Mint<M> {
                    let mut a = self.val as i32;
                    let mut b = self.module() as i32;
                    let mut u = 1 as i32;
                    let mut v = 0 as i32;
                    while b != 0 {
                        let t = a / b;
                        a -= t * b;
                        mem::swap(&mut a, &mut b);
                        u -= t * v;
                        mem::swap(&mut u, &mut v);
                    }
                    Mint::new(if u < 0 { u + self.module() as i32 } else { u } as u32)
                }
            }
            impl<M: Module> PartialEq for Mint<M> {
                fn eq(&self, other: &Mint<M>) -> bool {
                    self.val == other.val
                }
            }
            impl<M: Module> fmt::Display for Mint<M> {
                fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
                    self.val.fmt(f)
                }
            }
            macro_rules ! impl_signed_mint { ( $ ( $ t : ty ) * ) => ( $ ( impl < M : Module > From <$ t > for Mint < M > { # [ inline ] fn from ( x : $ t ) -> Mint < M > { let t = ( x as i64 ) % ( M :: module ( ) as i64 ) ; if x >= 0 { Mint { val : t as u32 , m : PhantomData } } else { Mint { val : ( M :: module ( ) as i64 + t ) as u32 , m : PhantomData } } } } ) * ) }
            macro_rules ! impl_unsigned_mint { ( $ ( $ t : ty ) * ) => ( $ ( impl < M : Module > From <$ t > for Mint < M > { # [ inline ] fn from ( x : $ t ) -> Mint < M > { let t = x as u64 % M :: module ( ) as u64 ; Mint :: new ( t as u32 ) } } ) * ) }
            impl_signed_mint! { i8 i16 i32 i64 isize }
            impl_unsigned_mint! { u8 u16 u32 u64 usize }
            impl<T: Into<Mint<M>>, M: Module> ops::AddAssign<T> for Mint<M> {
                fn add_assign(&mut self, other: T) {
                    *self = *self + other.into();
                }
            }
            impl<T: Into<Mint<M>>, M: Module> ops::SubAssign<T> for Mint<M> {
                fn sub_assign(&mut self, other: T) {
                    *self = *self - other.into();
                }
            }
            impl<T: Into<Mint<M>>, M: Module> ops::MulAssign<T> for Mint<M> {
                fn mul_assign(&mut self, other: T) {
                    *self = *self * other.into();
                }
            }
            impl<T: Into<Mint<M>>, M: Module> ops::DivAssign<T> for Mint<M> {
                fn div_assign(&mut self, other: T) {
                    *self = *self / other.into();
                }
            }
            #[cfg(test)]
            mod tests {
                use super::*;
                #[test]
                fn test_simple() {
                    let a: Mint<Mod107> = Mint::from(3);
                    let b: Mint<Mod107> = Mint::from(1000000000);
                    assert_eq!(Mint::from(3000000000u64 % Mod107::module() as u64), a * b);
                }
            }
        }
        pub use self::comb::Comb;
        pub use self::mint::{Mint, Module};
        pub use self::mint::{Mint107, Mint109, Mint998};
        pub use self::mint::{Mod107, Mod109, Mod998};
        pub use self::mint::{MOD_107, MOD_109, MOD_998};
    }
    pub mod util {
        mod permutation {
            #[doc = " It contains same methods as `std::next_permutaion` in C++."]
            #[doc = " these methods should rearrange the elements into the next/prev lexicographically greater permutation."]
            #[doc = ""]
            #[doc = " This is implemented in [T] where T is Ord."]
            #[doc = ""]
            #[doc = " # Examples"]
            #[doc = " ```"]
            #[doc = " use algonium::util::Permutation;"]
            #[doc = ""]
            #[doc = " let mut perm = [5, 0, 9, 2];"]
            #[doc = " assert!(perm.next_permutation());"]
            #[doc = " assert_eq!(perm, [5, 2, 0, 9]);"]
            #[doc = " assert!(perm.next_permutation());"]
            #[doc = " assert_eq!(perm, [5, 2, 9, 0]);"]
            #[doc = " assert!(perm.prev_permutation());"]
            #[doc = " assert_eq!(perm, [5, 2, 0, 9]);"]
            #[doc = ""]
            #[doc = " let mut perm = [4, 3, 2, 1, 0];"]
            #[doc = " assert!(!perm.next_permutation());"]
            #[doc = " assert_eq!(perm, [4, 3, 2, 1, 0]);"]
            #[doc = " ```"]
            pub trait Permutation {
                #[doc = " It rearranges the elements into the next lexicographically greater permutation."]
                #[doc = ""]
                #[doc = " Returns `false` without modifying any state only if current is the last permutation."]
                fn next_permutation(&mut self) -> bool;
                #[doc = " It rearranges the elements into the previous lexicographically greater permutation."]
                #[doc = ""]
                #[doc = " Returns `false` without modifying any state only if current is the first permutation."]
                fn prev_permutation(&mut self) -> bool;
            }
            impl<T> Permutation for [T]
            where
                T: Ord,
            {
                fn next_permutation(&mut self) -> bool {
                    if self.len() <= 1 {
                        return false;
                    }
                    let mut i = self.len() - 1;
                    while i > 0 && self[i - 1] >= self[i] {
                        i -= 1;
                    }
                    if i == 0 {
                        return false;
                    }
                    let mut j = self.len() - 1;
                    while self[j] <= self[i - 1] {
                        j -= 1;
                    }
                    self.swap(j, i - 1);
                    self[i..].reverse();
                    true
                }
                fn prev_permutation(&mut self) -> bool {
                    if self.len() <= 1 {
                        return false;
                    }
                    let mut i = self.len() - 1;
                    while i > 0 && self[i - 1] <= self[i] {
                        i -= 1;
                    }
                    if i == 0 {
                        return false;
                    }
                    self[i..].reverse();
                    let mut j = self.len() - 1;
                    while self[j - 1] < self[i - 1] {
                        j -= 1;
                    }
                    self.swap(i - 1, j);
                    true
                }
            }
            #[cfg(test)]
            mod tests {
                use super::*;
                #[test]
                fn test_simple() {
                    let mut data = [0, 0, 1, 1, 2];
                    data.next_permutation();
                    assert_eq!(&data, &[0, 0, 1, 2, 1]);
                    data.next_permutation();
                    assert_eq!(&data, &[0, 0, 2, 1, 1]);
                    data.next_permutation();
                    assert_eq!(&data, &[0, 1, 0, 1, 2]);
                    data.next_permutation();
                    assert_eq!(&data, &[0, 1, 0, 2, 1]);
                    data.next_permutation();
                    assert_eq!(&data, &[0, 1, 1, 0, 2]);
                    data.prev_permutation();
                    assert_eq!(&data, &[0, 1, 0, 2, 1]);
                    data.prev_permutation();
                    assert_eq!(&data, &[0, 1, 0, 1, 2]);
                    data.prev_permutation();
                    assert_eq!(&data, &[0, 0, 2, 1, 1]);
                    data.prev_permutation();
                    assert_eq!(&data, &[0, 0, 1, 2, 1]);
                    data.prev_permutation();
                    assert_eq!(&data, &[0, 0, 1, 1, 2]);
                    assert!(!data.prev_permutation());
                }
            }
        }
        mod random {
            use std::num::Wrapping;
            #[doc = " Not secure but fast random generator."]
            #[doc = ""]
            #[doc = " # Examples"]
            #[doc = " ```"]
            #[doc = " use algonium::util::XorShift;"]
            #[doc = " let mut xorshift = XorShift::new();"]
            #[doc = " assert_eq!(3701687786, xorshift.next_u32());"]
            #[doc = " assert_eq!(458299110, xorshift.next_u32());"]
            #[doc = " ```"]
            #[derive(Clone, Debug, Default)]
            pub struct XorShift {
                x: Wrapping<u32>,
                y: Wrapping<u32>,
                z: Wrapping<u32>,
                w: Wrapping<u32>,
            }
            impl XorShift {
                #[doc = " Create object with default seed."]
                pub fn new() -> XorShift {
                    XorShift {
                        x: Wrapping(123_456_789),
                        y: Wrapping(362_436_069),
                        z: Wrapping(521_288_629),
                        w: Wrapping(88_675_123),
                    }
                }
                #[doc = " Get next random u32 number."]
                pub fn next_u32(&mut self) -> u32 {
                    let x = self.x;
                    let t = x ^ (x << 11);
                    self.x = self.y;
                    self.y = self.z;
                    self.z = self.w;
                    let v = self.w;
                    self.w = v ^ (v >> 19) ^ (t ^ (t >> 8));
                    self.w.0
                }
            }
            #[cfg(test)]
            mod tests {
                use super::XorShift;
                #[test]
                fn test_basic() {
                    let mut xorshift = XorShift::new();
                    assert_eq!(3701687786, xorshift.next_u32());
                    assert_eq!(458299110, xorshift.next_u32());
                }
            }
        }
        pub use self::permutation::Permutation;
        pub use self::random::XorShift;
    }
}

//}}}