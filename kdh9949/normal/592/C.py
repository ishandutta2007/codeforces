from fractions import gcd
t,w,b=map(int,input().split())
p=int(t//(w*b//gcd(w,b)))*(min(w,b))+min(w-1,b-1,t%(w*b//gcd(w,b)))
print(str(int(p//gcd(p,t)))+'/'+str(int(t//gcd(p,t))))