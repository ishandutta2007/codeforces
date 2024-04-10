n, m = [int(i) for i in raw_input().split()]

def f(x):
    return x * (x-1) / 2

def mx(n, m):
    return f(n-m+1)

def mn(n, m):
    s = n/m
    return f(s+1) * (n%m) + f(s) * (m-n%m)

print mn(n, m), mx(n, m)