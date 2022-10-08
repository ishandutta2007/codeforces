n = int(input())

ile = 0
wyn = 0

for i in range(n):
  buf = input().split(" ")
  a = int(buf[0])
  b = int(buf[1])
  ile -= a
  ile += b
  wyn = max(wyn, ile)

print(wyn)