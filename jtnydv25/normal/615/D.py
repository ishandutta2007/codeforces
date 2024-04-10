mod = 10**9+7
md = (mod-1)/2
mod2 = mod-1
def inv(a,p):
    return pow(a,p-2,p)
factors={}
inv1 = inv(2,md)
inv2 = inv(md,2)
for t in range(0,1):
    m = input()
    A = map(int,raw_input().split())            
    prod = 1
    n_even=0
    ans = 1
    for j in range(0,len(A)):
        i = A[j]
        if factors.has_key(i) == False :
            factors[i] = 1
        else:
            factors[i]+=1       
    for i in factors:
        prod=(prod*(factors[i]+1))%(md)
        n_even+=(factors[i])%2
    for i  in factors:
        j = factors[i]
        x = pow(i,(j*(j+1))/2,mod)
        pwr = prod
        mod_md = (prod*inv(j+1,md))%md
        mod_2 = 1
        if n_even>=2 or (n_even == 1 and j%2==0):
            mod_2 = 0
        # mod_md gives the number of divisors of the remaining number modulo md
        # mod_2 gives the same mofdulo 2
        # Use CRT now to find modulo mod-1
        # p1 *(p1^(-1)mod p2)*a2 + p2*(p2^(-1) mod p1)*a1
        mod_mod2 = (2*inv1*mod_md + md*inv2*mod_2)%mod2 # gives the number of divisors of remaining number modulo 1000000006 (or phi(mod))
        ans=(ans*pow(x,mod_mod2,mod))%mod
    print(ans)