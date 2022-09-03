n = int(input().split()[1])
r = 0
for x in map(int, input().split()):
  r += (x + n - 1) // n
print(r)