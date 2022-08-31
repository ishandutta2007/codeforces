mod = 10**9+7
def f(p,k):
    if(k == 0):
        return pow(p,p-1,mod)
    if k == 1:
        return pow(p,p,mod)
    if k> 1:
        #order_p(r)
        r = 1
        k_1 = k
        while k != 1:
            r+=1
            k=(k*k_1)%p
        return pow(p,(p-1)/r,mod)
p,k = map(int,raw_input().split())
print f(p,k)