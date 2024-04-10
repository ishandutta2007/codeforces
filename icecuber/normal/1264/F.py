n, a, d = map(int, input().split())
mod = 10**12
step = pow(677449, 4*10**11-1, mod)
print(step*a%mod*1500000+1, step*d%mod*1500000)