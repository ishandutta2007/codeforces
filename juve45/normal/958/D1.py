n = int(input())
a = []
M = dict()
for i in range(n):
  a.append(eval(input()))
  M[a[-1]] = M.get(a[-1], 0) + 1

for i in range(n):
  print(M[a[i]], end=' ')