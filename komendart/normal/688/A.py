n, d = [int(i) for i in input().split()]
ans = 0
l = 0
for i in range(d):
 s = input()
 if '0' in s:
  l += 1
  ans = max(ans, l)
 else:
  l = 0
print(ans)