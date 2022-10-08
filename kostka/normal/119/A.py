import fractions

buf = input().split(" ")

a = int(buf[0])
b = int(buf[1])
n = int(buf[2])

while True:
  x = fractions.gcd(a,n)
  if n >= x:
    n -= x
  else:
    print(1)
    break
  x = fractions.gcd(b,n)
  if n >= x:
    n -= x
  else:
    print(0)
    break