import sys
input = sys.stdin.buffer.readline 

def gcd(a, b):
    if a > b:
        a, b = b, a
    if b % a==0:
        return a
    return gcd(b % a, a)

dot = lambda v1, v2: sum(i * j for i, j in zip(v1, v2))

norm_sq = lambda v: sum(i * i for i in v)

def angle(oa, ob):
    num = dot(oa, ob)**2
    den = (norm_sq(oa) * norm_sq(ob))
    if num==0:
        return [0, 1]
    g = gcd(num, den)
    return [num//g, den//g]


def remove_middle(a, b, c):
    cross = (a[0] - b[0]) * (c[1] - b[1]) - (a[1] - b[1]) * (c[0] - b[0])
    return cross <= 0


def convex_hull(points):
    spoints = sorted(points)
    hull = []

    for rep in range(2):
        g = len(hull)
        for p in spoints:
            while len(hull)-g >= 2 and remove_middle(hull[-2], hull[-1], p):
                hull.pop()
            hull.append(p)
        hull.pop()
        spoints.reverse()
    
    return hull

def partial(s):
    g, pi = 0, [0] * len(s)
    for i in range(1, len(s)):
        while g and (s[g] != s[i]):
            g = pi[g - 1]
        pi[i] = g = g + (s[g] == s[i])

    return pi


def string_find(s, pat):
    pi = partial(pat)
    g = 0
    for i in range(len(s)):
        while g and pat[g] != s[i]:
            g = pi[g - 1]
        g += pat[g] == s[i]
        if g == len(pi):
            return True
    for i in range(len(s)):
        while g and pat[g] != s[i]:
            g = pi[g - 1]
        g += pat[g] == s[i]
        if g == len(pi):
            return True

    return False

n, m = [int(x) for x in input().split()]
A = []
for i in range(n):
    x, y = [int(x) for x in input().split()]
    A.append((x, y))
B = []
for i in range(n, n+m):
    x, y = [int(x) for x in input().split()]
    B.append((x, y))
A1 = convex_hull(A)
B1 = convex_hull(B)
if len(A1) != len(B1):
    print('NO')
    sys.exit()
"""
Can A1 be translated/rotated into B1?

"""
n = len(A1)
A2 = []
B2 = []
for i in range(n):
    x0, y0 = A1[(i-1) % n]
    x1, y1 = A1[i]
    x2, y2 = A1[(i+1) % n]
    vx, vy = x1-x0,y1-y0
    wx, wy = x2-x1,y2-y1
    A2.append((wx*wx+wy*wy,dot((vx,vy),(wx,wy)), vx*wy-vy*wx))
    x0, y0 = B1[(i-1) % n]
    x1, y1 = B1[i]
    x2, y2 = B1[(i+1) % n]
    vx, vy = x1-x0,y1-y0
    wx, wy = x2-x1,y2-y1
    B2.append((wx*wx+wy*wy,dot((vx,vy),(wx,wy)), vx*wy-vy*wx))
if not string_find(B2, A2):
    print('NO')
else:
    print('YES')