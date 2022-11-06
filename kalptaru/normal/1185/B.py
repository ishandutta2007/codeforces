n=int(input())
for _ in range(n):
    s=input()
    t=input()
    j=0
    l=s[0]
    s1=[]
    t1=[]
    flag1=True
    for i in s:
        if(l==i):
            j+=1
        else:
            s1.append([l,j])
            l=i
            j=1
    s1.append([l,j])
    l=t[0]
    j=0
    for i in t:
        if(l==i):
            j+=1
        else:
            t1.append([l,j])
            l=i
            j=1
    t1.append([l,j])
    if(len(s1)!=len(t1)):
        flag1=False
    else:
        for i in range(len(s1)):
            if not (s1[i][0]==t1[i][0] and s1[i][1]<=t1[i][1]):
                flag1=False
                break 
    if(flag1):
        print('YES')
    else:
        print('NO')