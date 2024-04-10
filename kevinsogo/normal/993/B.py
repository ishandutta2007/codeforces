if 1:
    from sys import *
    from functools import *
    from collections import *
    from itertools import *
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

def get_pairs(t):
    pairs = parts()
    assert len(pairs) % 2 == 0
    assert len(pairs) / 2 == t
    ps = []
    for i in xrange(0, len(pairs), 2):
        ps.append((pairs[i], pairs[i + 1]))
    assert len(ps) == t
    return ps

n, m = parts()
ps = get_pairs(n)
qs = get_pairs(m)

vals = sorted({a for pst in [ps, qs] for pr in pst for a in pr})

def partners(x, ps):
    partners = set()
    for a, b in ps:
        if a == x: partners.add(b)
        if b == x: partners.add(a)
    return partners

def can_be(x):
    pap = partners(x, ps)
    paq = partners(x, qs)
    if not pap or not paq: return False
    for x in pap:
        if paq - {x}: return True
    for x in paq:
        if pap - {x}: return True
    return False

def good(v, p, qs):
    return (not (partners(v, qs) - {p})) ^ (not (partners(p, qs) - {v}))

def can_deduce(ps, qs, v):
    for p in partners(v, ps):
        if not good(v, p, qs):
            return False
    return True


goodp = goodq = True
okays = set()
for v in vals:
    if can_be(v):
        okays.add(v)
        if not can_deduce(ps, qs, v): goodp = False
        if not can_deduce(qs, ps, v): goodq = False

if len(okays) == 1:
    [v] = okays
    print v
elif goodp and goodq:
    print 0
else:
    print -1