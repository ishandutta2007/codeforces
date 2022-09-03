input()
a = [0] * 123456
d = [0] * 123456
for x in map(int, input().split()):
  a[x] += 1
d[1] = a[1]
for i in range(2, 123456):
  d[i] = max(d[i - 1], d[i - 2] + a[i] * i)
print(d[123455])