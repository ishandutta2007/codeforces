#![allow(unknown_lints)]
#![allow(unused_imports, unused_macros, non_snake_case, bare_trait_objects)]
#![allow(renamed_and_removed_lints, redundant_field_names)]
use std::cmp::Ordering::{self, Greater, Less};
use std::cmp::{max, min};
use std::collections::{BTreeMap, BTreeSet, BinaryHeap, HashMap, HashSet, VecDeque};
use std::error::Error;
use std::io::{self, BufReader, BufWriter, Read, Write};
use text_scanner::{read_line, scan, scan_iter, scanln, scanln_iter};
use utils::adj4_iter;

fn run() {
    // WARNING: usize is 32bit!
    // WARNING: scan() and println!() of 10^5 integers takes 1.3 seconds!
    let t: usize = read_line().unwrap().parse::<usize>().unwrap();
    let mut output = String::new();
    const M: i64 = 1_000_000_007;
    for _ in 0..t {
        let n: usize = read_line().unwrap().parse::<usize>().unwrap();
        let v: Vec<i64> = read_line()
            .unwrap()
            .split_whitespace()
            .into_iter()
            .map(|x| x.parse::<i64>().unwrap())
            .collect();
        let mut counter = vec![0; 61];
        for i in 0..n {
            for j in 0..61 {
                if v[i] >> j & 1 != 0 {
                    counter[j] += 1;
                }
            }
        }
        let mut base: Vec<i64> = vec![0; 61];
        for i in 0..61 {
            base[i] = (1 << i) % M;
        }

        let mut ans: i64 = 0;
        for i in 0..n {
            let mut left: i64 = 0;
            for j in 0..61 {
                if v[i] >> j & 1 == 0 {
                    continue;
                }
                left += counter[j] * base[j];
                left %= M;
            }
            let mut right: i64 = 0;
            for j in 0..61 {
                if v[i] >> j & 1 == 0 {
                    right += counter[j] * base[j];
                    right %= M;
                } else {
                    right += (n as i64) * base[j];
                    right %= M;
                }
            }
            ans += left * right % M;
            ans %= M;
        }
        output += &format!("{}\n", ans);
    }
    print!("{}", output);
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
pub mod utils {
    static DY: [isize; 8] = [0, 1, 0, -1, 1, -1, 1, -1];
    static DX: [isize; 8] = [1, 0, -1, 0, 1, 1, -1, -1];

    fn try_adj(
        y: usize,
        x: usize,
        dy: isize,
        dx: isize,
        h: usize,
        w: usize,
    ) -> Option<(usize, usize)> {
        let ny = y as isize + dy;
        let nx = x as isize + dx;
        if ny >= 0 && nx >= 0 {
            let ny = ny as usize;
            let nx = nx as usize;
            if ny < h && nx < w {
                Some((ny, nx))
            } else {
                None
            }
        } else {
            None
        }
    }

    pub struct Adj4 {
        y: usize,
        x: usize,
        h: usize,
        w: usize,
        r: usize,
    }

    impl Iterator for Adj4 {
        type Item = (usize, usize);

        fn next(&mut self) -> Option<Self::Item> {
            loop {
                if self.r >= 4 {
                    return None;
                }

                let dy = DY[self.r];
                let dx = DX[self.r];
                self.r += 1;

                if let Some((ny, nx)) = try_adj(self.y, self.x, dy, dx, self.h, self.w) {
                    return Some((ny, nx));
                }
            }
        }
    }

    pub fn adj4_iter(y: usize, x: usize, h: usize, w: usize) -> Adj4 {
        Adj4 {
            y: y,
            x: x,
            h: h,
            w: w,
            r: 0,
        }
    }
}
pub mod text_scanner {
    use std;
    #[derive(Debug)]
    pub enum Error {
        IoError(std::io::Error),
        EncodingError(std::string::FromUtf8Error),
        ParseError(String),
        Eof,
    }

    impl std::fmt::Display for Error {
        fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
            match *self {
                Error::IoError(ref e) => writeln!(f, "IO Error: {}", e),
                Error::EncodingError(ref e) => writeln!(f, "Encoding Error: {}", e),
                Error::ParseError(ref e) => writeln!(f, "Parse Error: {}", e),
                Error::Eof => writeln!(f, "EOF"),
            }
        }
    }

    impl std::error::Error for Error {
        // dummy implementation for 1.15.1
        fn description(&self) -> &str {
            "description() is deprecated; use Display"
        }
    }

    pub fn read_line() -> Option<String> {
        let stdin = std::io::stdin();
        let mut stdin = stdin.lock();
        fread_line(&mut stdin).expect("IO error")
    }

    pub fn scan<T: FromTokens>() -> T {
        let stdin = std::io::stdin();
        let mut stdin = stdin.lock();
        fscan(&mut stdin).expect("IO error")
    }

    pub fn scanln<T: FromTokens>() -> T {
        let stdin = std::io::stdin();
        let mut stdin = stdin.lock();
        fscanln(&mut stdin).expect("IO error")
    }

    pub fn scan_iter<T: FromTokens>() -> ScanIter<T> {
        ScanIter {
            item_type: std::marker::PhantomData,
        }
    }

    pub fn scanln_iter<T: FromTokens>() -> ScanlnIter<T> {
        let stdin = std::io::stdin();
        let mut stdin = stdin.lock();
        let s = fread_line(&mut stdin)
            .expect("IO error")
            .unwrap_or_else(String::new);
        ScanlnIter {
            cursor: std::io::Cursor::new(s),
            item_type: std::marker::PhantomData,
        }
    }

    pub fn fread_line<R: std::io::BufRead>(r: &mut R) -> Result<Option<String>, std::io::Error> {
        let mut buf = String::new();
        let length = r.read_line(&mut buf)?;
        if let Some('\n') = buf.chars().last() {
            buf.pop();
        }
        if let Some('\r') = buf.chars().last() {
            buf.pop();
        }
        if length == 0 {
            Ok(None)
        } else {
            Ok(Some(buf))
        }
    }

    pub fn fscan<R: std::io::Read, T: FromTokens>(reader: &mut R) -> Result<T, Error> {
        let mut tokenizer = Tokenizer::new(reader);
        FromTokens::from_tokens(&mut tokenizer)
    }

    pub fn fscanln<R: std::io::BufRead, T: FromTokens>(reader: &mut R) -> Result<T, Error> {
        let s = match fread_line(reader) {
            Ok(Some(s)) => s,
            Ok(None) => return Err(Error::Eof),
            Err(e) => return Err(Error::IoError(e)),
        };
        let mut bytes = s.as_bytes();
        let mut tokenizer = Tokenizer::new(&mut bytes);
        FromTokens::from_tokens(&mut tokenizer)
    }

    pub fn fscan_iter<R: std::io::Read, T: FromTokens>(reader: &mut R) -> FscanIter<R, T> {
        FscanIter {
            tokenizer: Tokenizer::new(reader),
            item_type: std::marker::PhantomData,
        }
    }

    pub fn fscanln_iter<R: std::io::BufRead, T: FromTokens>(
        reader: &mut R,
    ) -> Result<ScanlnIter<T>, Error> {
        let s = match fread_line(reader) {
            Ok(Some(s)) => s,
            Ok(None) => "".to_string(),
            Err(e) => return Err(Error::IoError(e)),
        };
        Ok(ScanlnIter {
            cursor: std::io::Cursor::new(s),
            item_type: std::marker::PhantomData,
        })
    }

    pub struct ScanIter<T>
    where
        T: FromTokens,
    {
        item_type: std::marker::PhantomData<T>,
    }

    impl<T: FromTokens> Iterator for ScanIter<T> {
        type Item = T;

        fn next(&mut self) -> Option<Self::Item> {
            let stdin = std::io::stdin();
            let mut stdin = stdin.lock();
            let mut tokenizer = Tokenizer::new(&mut stdin);
            match FromTokens::from_tokens(&mut tokenizer) {
                Err(Error::Eof) => None,
                r => Some(r.expect("IO error")),
            }
        }
    }

    pub struct FscanIter<'a, R, T>
    where
        R: std::io::Read + 'a,
        T: FromTokens,
    {
        tokenizer: Tokenizer<'a, R>,
        item_type: std::marker::PhantomData<T>,
    }

    impl<'a, R: std::io::Read, T: FromTokens> Iterator for FscanIter<'a, R, T> {
        type Item = Result<T, Error>;

        fn next(&mut self) -> Option<Self::Item> {
            match FromTokens::from_tokens(&mut self.tokenizer) {
                Err(Error::Eof) => None,
                r => Some(r),
            }
        }
    }

    pub struct ScanlnIter<T>
    where
        T: FromTokens,
    {
        cursor: std::io::Cursor<String>,
        item_type: std::marker::PhantomData<T>,
    }

    impl<'a, T: FromTokens> Iterator for ScanlnIter<T> {
        type Item = T;

        fn next(&mut self) -> Option<Self::Item> {
            let mut tokenizer = Tokenizer::new(&mut self.cursor);
            match FromTokens::from_tokens(&mut tokenizer) {
                Err(Error::Eof) => None,
                r => Some(r.expect("IO error")),
            }
        }
    }

    pub trait FromTokens
    where
        Self: Sized,
    {
        fn from_tokens(
            tokenizer: &mut Iterator<Item = Result<String, Error>>,
        ) -> Result<Self, Error>;
    }

    macro_rules! from_tokens_primitives {
    ($($t:ty),*) => { $(
        impl FromTokens for $t {
            fn from_tokens(tokenizer: &mut Iterator<Item = Result<String, Error>>) -> Result<Self, Error> {
                let token = tokenizer.next();
                match token {
                    Some(s) => s?
                        .parse::<$t>()
                        .map_err(|e| Error::ParseError(format!("{}", e))),
                    None => Err(Error::Eof),
                }
            }
        }
    )* }
}

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

    impl FromTokens for Vec<char> {
        fn from_tokens(
            tokenizer: &mut Iterator<Item = Result<String, Error>>,
        ) -> Result<Self, Error> {
            Ok(String::from_tokens(tokenizer)?.chars().collect())
        }
    }

    impl<T1, T2> FromTokens for (T1, T2)
    where
        T1: FromTokens,
        T2: FromTokens,
    {
        fn from_tokens(
            tokenizer: &mut Iterator<Item = Result<String, Error>>,
        ) -> Result<Self, Error> {
            Ok((T1::from_tokens(tokenizer)?, T2::from_tokens(tokenizer)?))
        }
    }

    impl<T1, T2, T3> FromTokens for (T1, T2, T3)
    where
        T1: FromTokens,
        T2: FromTokens,
        T3: FromTokens,
    {
        fn from_tokens(
            tokenizer: &mut Iterator<Item = Result<String, Error>>,
        ) -> Result<Self, Error> {
            Ok((
                T1::from_tokens(tokenizer)?,
                T2::from_tokens(tokenizer)?,
                T3::from_tokens(tokenizer)?,
            ))
        }
    }

    impl<T1, T2, T3, T4> FromTokens for (T1, T2, T3, T4)
    where
        T1: FromTokens,
        T2: FromTokens,
        T3: FromTokens,
        T4: FromTokens,
    {
        fn from_tokens(
            tokenizer: &mut Iterator<Item = Result<String, Error>>,
        ) -> Result<Self, Error> {
            Ok((
                T1::from_tokens(tokenizer)?,
                T2::from_tokens(tokenizer)?,
                T3::from_tokens(tokenizer)?,
                T4::from_tokens(tokenizer)?,
            ))
        }
    }

    impl<T1, T2, T3, T4, T5> FromTokens for (T1, T2, T3, T4, T5)
    where
        T1: FromTokens,
        T2: FromTokens,
        T3: FromTokens,
        T4: FromTokens,
        T5: FromTokens,
    {
        fn from_tokens(
            tokenizer: &mut Iterator<Item = Result<String, Error>>,
        ) -> Result<Self, Error> {
            Ok((
                T1::from_tokens(tokenizer)?,
                T2::from_tokens(tokenizer)?,
                T3::from_tokens(tokenizer)?,
                T4::from_tokens(tokenizer)?,
                T5::from_tokens(tokenizer)?,
            ))
        }
    }

    impl<T1, T2, T3, T4, T5, T6> FromTokens for (T1, T2, T3, T4, T5, T6)
    where
        T1: FromTokens,
        T2: FromTokens,
        T3: FromTokens,
        T4: FromTokens,
        T5: FromTokens,
        T6: FromTokens,
    {
        fn from_tokens(
            tokenizer: &mut Iterator<Item = Result<String, Error>>,
        ) -> Result<Self, Error> {
            Ok((
                T1::from_tokens(tokenizer)?,
                T2::from_tokens(tokenizer)?,
                T3::from_tokens(tokenizer)?,
                T4::from_tokens(tokenizer)?,
                T5::from_tokens(tokenizer)?,
                T6::from_tokens(tokenizer)?,
            ))
        }
    }

    struct Tokenizer<'a, R: std::io::Read + 'a> {
        reader: &'a mut R,
    }

    impl<'a, R: std::io::Read> Tokenizer<'a, R> {
        pub fn new(reader: &'a mut R) -> Self {
            Tokenizer { reader: reader }
        }

        pub fn next_token(&mut self) -> Result<Option<String>, Error> {
            use std::io::Read;
            let mut token = Vec::new();
            for b in self.reader.by_ref().bytes() {
                let b = b.map_err(Error::IoError)?;
                match (is_ascii_whitespace(b), token.is_empty()) {
                    (false, _) => token.push(b),
                    (true, false) => break,
                    (true, true) => {}
                }
            }
            if token.is_empty() {
                return Ok(None);
            }
            String::from_utf8(token)
                .map(Some)
                .map_err(Error::EncodingError)
        }
    }

    impl<'a, R: std::io::Read> Iterator for Tokenizer<'a, R> {
        type Item = Result<String, Error>;
        fn next(&mut self) -> Option<Self::Item> {
            match self.next_token() {
                Ok(Some(s)) => Some(Ok(s)),
                Ok(None) => None,
                Err(e) => Some(Err(e)),
            }
        }
    }

    fn is_ascii_whitespace(b: u8) -> bool {
        // Can use u8::is_ascii_whitespace once removing support of 1.15.1
        match b {
            b'\t' | b'\n' | b'\x0C' | b'\r' | b' ' => true,
            _ => false,
        }
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

#[derive(PartialEq, PartialOrd, Debug, Copy, Clone, Default)]
pub struct Num(pub f64);

impl Eq for Num {}

impl Ord for Num {
    fn cmp(&self, other: &Num) -> Ordering {
        self.0
            .partial_cmp(&other.0)
            .expect("unexpected NaN when compare")
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