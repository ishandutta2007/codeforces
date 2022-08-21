if 1:
    from sys import *
    from functools import *
    from collections import *
    from itertools import *
    from functools import *
    from heapq import *
    xr = xrange

    def print_args(*args, **kwargs):
        return ','.join(value for value in [','.join(map(repr, args)),','.join("%s=%s" % (k, repr(v)) for k, v in kwargs.items())] if value)

    def print_result(before=False, after=True):
        def fc(func):
            @wraps(func)
            def f(*args, **kwargs):
                if before:
                    print "%s(%s)"      % (func.__name__, print_args(*args, **kwargs))
                r = func(*args, **kwargs)
                if after:
                    print "%s(%s) = %s" % (func.__name__, print_args(*args, **kwargs), r)
                return r
            return f
        return fc

    def memoize(function):
        memo = {}
        @wraps(function)
        def f(*args):
            key = args
            if key not in memo:
                memo[key] = function(*args)
                if not (len(memo) & 32767):
                    print >>stderr, "memo", function.__name__, len(memo)
            return memo[key]
        f.memo = memo
        return f

    def line():
        return raw_input().strip()

    def parts(f=int):
        return map(f, line().split())

    def qparts(f=int):
        data = line().split()
        return data[0], map(f, data[1:])

    def apply_after(after):
        def _apply_after(function):
            @wraps(function)
            def f(*args, **kwargs):
                return after(function(*args, **kwargs))
            return f
        return _apply_after

    listify = apply_after(list)

mod = 10**9 + 7
@memoize
def fac(n):
    return 1 if n == 0 else n * fac(n - 1) % mod
@memoize
def ifc(n):
    return 1 if n == 0 else inv(n) * ifc(n - 1) % mod
@memoize
def inv(n):
    return 1 if n <= 1 else (mod - mod / n) * inv(mod % n) % mod
@memoize
def Ch(n, r):
    return 0 if r < 0 or r > n else fac(n) * ifc(n - r) * ifc(r) % mod
@memoize
def Co(n, r):
    return (-1)**r * Ch(n, r) * fac(n - 1) * ifc(n - 1 - r) % mod

N = 333
for n in xrange(2, N+1):
    fac(n)
    ifc(n)
    inv(n)

for n in xrange(2, N+1):
    for r in xrange(1, n):
        Ch(n, r)
        Co(n, r)

def sqfpart(n):
    f = n
    p = 2
    while p * p <= f:
        pp = p * p
        while f % pp == 0:
            f /= pp
        p += 1
    return f

ln = input()
nums = parts()
assert len(nums) == ln

vals = Counter(sqfpart(v) for v in nums).values()

@memoize
def _solve(n, i):
    if i == len(vals): return fac(n)
    return sum(_solve(n - j, i + 1) * Co(vals[i], j) % mod for j in xrange(vals[i])) % mod


print _solve(sum(vals), 0) % mod