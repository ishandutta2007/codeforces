
def gcd (q,w):
    if (q<w):
        t=q
        q=w
        w=t
    if (w==0):
        return q
    return gcd(q%w, w) 


def solve():
    s1=raw_input()
    s2=raw_input()
    a1=len(s1)
    a2=len(s2)
    g=gcd(a1, a2)
    mod=1000000007
    ans=0
    hash1=[]
    hash2=[]
    step=[]
    for i in range(0, a1):
        hash1.append(0)
    for i in range(0, a2):
        hash2.append(0)
    step.append(1)
    for i in range (1, a1+a2+1):
        step.append((step[i-1]*2011)%mod)
    hash1[0]=ord(s1[0]);
    for i in range (1, a1):
        hash1[i]=(hash1[i-1]*2011+ord(s1[i]))%mod
    hash2[0]=ord(s2[0]);
    for i in range (1, a2):
        hash2[i]=(hash2[i-1]*2011+ord(s2[i]))%mod
    for i in range(1, g+1):
        if (g%i==0):
            cur=hash1[i-1]
            f=True
            for j in range (2, a1/i+1):
                if ((hash1[i*j-1]-(step[i]*hash1[i*j-1-i])%mod+mod)%mod!=cur):
                    f=False
                    break
            if (f==True):
                now=hash2[i-1]
                if (now!=cur):
                    f=False
                if (f==True):
                    for j in range (2, a2/i+1):
                        if ((hash2[i*j-1]-(step[i]*hash2[i*j-1-i])%mod+mod)%mod!=cur):
                            f=False
                            break
            if (f==True):
                ans+=1
    print(ans)
        
if __name__ == "__main__":
    solve()