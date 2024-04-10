N=int(input())
M=list(map(int, input().split()))
R=list(map(int, input().split()))

def gcd(a, b):
    if b == 0: return a
    return gcd(b, a % b)

def lcm(a, b):
    return a*b//gcd(a,b)

s=1
for m in M: s = lcm(s, m)
t=0
for d in range(s):
    k = False
    for i, m in enumerate(M):
        r = R[i]
        if d % m == r:
            k = True
            break
    if k: t += 1

print(t/s)