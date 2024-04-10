a = int(input())
r = 0
for x in sorted(map(int, input().split()))[::-1]:
  if a > 0:
    a -= x
    r += 1
print(r if a <= 0 else -1)