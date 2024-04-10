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

def get_square():
    a, b, c, d, e, f, g, h = [y*4 for y in parts()]
    return [(a, b), (c, d), (e, f), (g, h)]

p = get_square()
q = get_square()

X = 450

def cross((a, b), (c, d)):
    return a * d - b * c

def sub((a, b), (c, d)):
    return a - c, b - d

def tri(a, b, c):
    return cross(sub(a, c), sub(b, c))

def contains(q, pt):
    ta = 0
    tb = 0
    for i in xrange(len(q)):
        ar = tri(q[i - 1], q[i], pt)
        ta += ar
        tb += abs(ar)
    return abs(ta) == tb


# def intersects(a, b, c, d):
#     return (
#         seg_contains(a, b, c) or seg_contains(a, b, d) or
#         seg_contains(c, d, a) or seg_contains(c, d, b) or
#         cross(sub(c, a), sub(b, a)) * cross(sub(d, a), sub(b, a)) < 0

# def good(p, q):
#     for pt in p:
#         if contains(q, pt):
#             return True
#     for i in xrange(len(p)):
#         for j in xrange(len(q)):
#             if intersects(p[i - 1], p[i], q[i - 1], q[i]):
#                 return True
#     return False

def good(p, q):
    for x in xrange(-X,X+1):
        for y in xrange(-X,X+1):
            if contains(p, (x, y)) and contains(q, (x, y)):
                return True
    return False


print 'Yes' if good(p, q) else 'No'