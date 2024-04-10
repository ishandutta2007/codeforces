n,m = map(int,input().split())
a = input()
b = input()
if n > m: b = '0'*(n-m) + b
elif m > n: a = '0'*(m-n) + a
ans = cnt = 0
mod = 998244353
for i in range(max(n,m)):
    if b[i] == '1': cnt += 1
    if a[i] == '1':
        ans = (ans+cnt*pow(2,max(n,m)-i-1,mod))%mod
print(ans)