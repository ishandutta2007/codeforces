n,m=[int(i) for i in input().split()]
q1=[]
q0=[]
arr=[-1]*n
for _ in range(m):
    q=[int(i) for i in input().split()]
    if(q[0]==0):
        q0.append(q)
    else:
        q1.append(q)
for i in range(len(q1)):
    l=q1[i][1]
    r=q1[i][2]
    if(arr[l-1]==-1):
        if(arr[r-1]==-1):
            for j in range(l-1,r):
                arr[j]=i
        else:
            for j in range(l-1,r):
                arr[j]=arr[r-1]
    else:
        if(arr[r-1]==-1):
            for j in range(l-1,r):
                arr[j]=arr[l-1]
        elif(arr[r-1]!=arr[l-1]):
            for j in range(l,r-1):
                arr[j]=arr[l-1]
            u=r
            while(arr[u]==arr[r-1]):
                arr[u]=arr[l-1]
                u+=1
                if u==n:
                    break
            arr[r-1]=arr[l-1]
flag=True
for i in q0:        
    l=i[1]-1
    r=i[2]-1
    if(arr[l]==arr[r] and arr[l]!=-1):
        flag=False
        break
if flag:
    p=-2
    j=1
    for i in range(1,n+1):
        if(arr[-i]==-1):
            j+=1
            arr[-i]=j
        elif(arr[-i]==p):
            arr[-i]=j
        else:
            p=arr[-i]
            j+=1
            arr[-i]=j
    print("YES")
    print(*arr)
else:
    print("NO")