t=int(input())
for _ in range (t):
    n=int(input())
    arr=[int(x) for x in input().split()]
    used=[0]*(n+5)
    cnt=0
    frnt=[]
    end=[]
    for i in range (n):
        if used[arr[i]]==0:
            used[arr[i]]=1
            frnt.append(arr[i])
        if(used[arr[2*n-1-i]])==0:
            used[arr[2*n-1-i]]=1
            end.insert(0,arr[2*n-1-i])
    print(' '.join(map(str,frnt))+" "+' '.join(map(str,end)))