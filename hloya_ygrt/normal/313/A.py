def mod(n,base):
    if (n >= 0):
        return n % base
    else:
        return (-1)*((-1)*n % base)
n = int(input())
if ( n >= 0):
    print(n)
    exit(0)
sv = int(n)
sv = int(sv / 10)
if (mod(n,10) < mod(sv,10)):
    print(int(n/10))
else:
    print(int(n/100)*10 + mod(n,10))