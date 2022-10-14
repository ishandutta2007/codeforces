from math import comb
MOD = 998244353

wins = [0]*61
loses = [0]*61
for n in range(2,61,2):
    wins[n] = loses[n-2] + comb(n-1,n//2)
    loses[n] = wins[n-2] + comb(n-2,n//2)
    wins[n]%=MOD
    loses[n]%=MOD

for _ in range(int(input())):
    n = int(input())
    print(wins[n],loses[n],1)