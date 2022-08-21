from functools import wraps

def memoize(function):
  memo = {}
  @wraps(function)
  def f(*args, **kwargs):
    key = args, tuple(sorted(kwargs.items()))
    if key not in memo:
      memo[key] = function(*args, **kwargs)
    return memo[key]
  f.memo = memo
  return f

'''
from itertools import count

@memoize
def grundy(n,v=None):
  if v is None:
    return grundy(n,(1<<n)-1<<1)
  if v == 0:
    return 0
  s = set()
  for i in xrange(1,n+1):
    if (v & (1 << i)):
      w = v
      j = i
      while j <= n:
        w &= ~(1 << j)
        j += i
      s.add(grundy(n,w))
  for i in count():
    if i not in s:
      return i

for i in xrange(31):
  print i, grundy(i)

'''

grundies = [
0,
1,
2,
1,
4,
3,
2,
1,
5,
6,
2,
1,
8,
7,
5,
9,
8,
7,
3,
4,
7,
4,
2,
1,
10,
9,
3,
6,
11,
12,
14,
]# :D
def grundy(n):
  return grundies[n]

@memoize
def kthroot(n,k):
  if k == 1:
    return n
  if n == 1:
    return 1
  a = 1
  while (a+1)**k <= n:
    a += 1
  return a



n = input()

ones = n
merns = set()
sn = kthroot(n,2)
v = set(i for i in xrange(2,sn+1))
for i in xrange(2,sn+1):
  if i in v:
    k = 1
    pi = i
    v.remove(i)
    while pi * i <= n:
      k += 1
      pi *= i
      if pi in v:
        v.remove(pi)
    if k in merns:
      merns.remove(k)
    else:
      merns.add(k)
    ones -= k

gr = ones & 1

#print merns, ones
for v in merns:
  gr ^= grundy(v)

print 'Vasya' if gr else 'Petya'