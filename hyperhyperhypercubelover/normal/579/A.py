x = int(input())
r = 0
while x:
  r += x & 1
  x >>= 1
print(r)