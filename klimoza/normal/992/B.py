import math



def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)


l, r, x, y = map(int, input().split())
lwall = math.ceil(l / x)
rwall = math.floor(r / x)
n = y // x
ans = 0
if(y % x != 0):
    print(0)
else:
    for i in range(1, int(math.sqrt(n)) + 1):
        if(n % i == 0 and lwall <= i and i <= rwall and gcd(i, n / i) == 1 and (n / i) <= rwall):
            ans += 2
            if(i == math.sqrt(n)):
                ans -= 1
    print(ans)