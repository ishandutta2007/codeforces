n = int(input().split()[1])
r = 0
for x in map(int, input().split()):
  if x + n < 6:
    r += 1
print(r // 3)