n=int(input())
a=n*[0]
for i in range(n):
    a[i]=list(map(int,input().split()))
    a[i][0]-=1
    a[i][1]-=1
w=[0]
while 1:
    if len(w)>=n:
        if len(w)>n:
            w=w[:-1]
        s=''
        for i in w:
            s+=str(i+1)+' '
        print(s)
        break
    c=a[w[-1]][:]
    if c[0] in a[c[1]]:
        w+=[c[1],c[0]]
    else:
        w+=[c[0],c[1]]