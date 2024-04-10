import sys

class FenwickTree(object):
  def __init__(self, n):
    self.n = n
    self.a = [10**9 for i in xrange(n)]
    self.global_opt = 10**9

  def put(self, i, val):
    self.global_opt = min(self.global_opt, val)
    while i < self.n:
      self.a[i] = min(self.a[i], val)
      i = (i | (i + 1))

  def get(self, r):
    res = 10**9
    while r >= 0:
      if res > self.a[r]:
        res = self.a[r]
      if res == self.global_opt:
        break
      r = (r & (r + 1)) - 1
    return res

n, m = [int(x) for x in raw_input().split()]
a = [int(x) for x in raw_input().split()]

prev = [-1 for i in xrange(0, len(a))]
prev_map = {}
for i in xrange(0, len(a)):
  if a[i] in prev_map:
    prev[i] = prev_map[a[i]]
  prev_map[a[i]] = i

data = sys.stdin.readlines()
queries = [[] for i in xrange(n)]
for i in xrange(m):
  l, r = data[i].split()  
  queries[int(r) - 1].append((int(l) - 1, i))

tree = FenwickTree(2 ** 19)
res = [None for i in xrange(0, m)]
L = -1
for r in xrange(n):
  if prev[r] != -1:
    tree.put(500000 - prev[r] + 1, r - prev[r])
    L = max(L, prev[r])
  for (l, ind) in queries[r]:
    if l > L:
      res[ind] = -1
      continue
    val = tree.get(500000 - l + 1)
    if val == 10**9:
      val = -1
    res[ind] = val

print('\n'.join(str(val) for val in res))