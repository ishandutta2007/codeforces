n=int(input())
a={}
e=''
for i in range(n):
    s=input()
    if s in a:
        d=a[s]
        e+=s+str(d)+'\n'
        a[s]+=1
    else:
        a[s]=1
        e+="OK\n"
print(e)