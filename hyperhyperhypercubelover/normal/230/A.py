n, m = map(int, input().split())
for x in sorted(list(map(int, input().split())) for _ in range(m)):
  if x[0] < n:
    n += x[1]
  else:
    print('NO')
    exit(0)
print('YES')