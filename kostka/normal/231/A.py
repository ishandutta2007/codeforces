n = int(input())

wyn = 0

for i in range(n):
  buf = input().split(" ")
  a = int(buf[0])
  b = int(buf[1])
  c = int(buf[2])
  if a+b+c>=2:
    wyn += 1

print(wyn)