import bisect
input()
a = [0]
for x in map(int, input().split()):
  a.append(a[-1] + x)
input()
for x in map(int, input().split()):
  print(bisect.bisect_left(a, x))