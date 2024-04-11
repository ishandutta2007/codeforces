from sys import stdout
n = int(input())
def q(l, f, s):
    print("?", f*l + s*(n-l))
    stdout.flush()
    return int(input())
a = "0"
b = "1"
x = q(0, a, b)
y = q(1, a, b)
if y > x:
    t = a
    a = b
    b = t
tot = q(0, a, b)
lo = 1
hi = n
while lo < hi:
    mid = lo + (hi - lo)//2
    if(q(mid, a, b)+mid == tot):
        lo = mid+1
    else:
        hi = mid
if a == "0":
    print("!",lo-1, lo)
else:
    print("!",lo, lo-1)