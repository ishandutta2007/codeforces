t=int(input())
for _ in range (t):
    n=int(input())
    arr=[int(x) for x in input().split()]
    inc=True
    brk=False
    ans=0
    for i in range (n-1):
        if brk==False:
            if inc==True:
                if arr[n-i-2]<arr[n-i-1]:
                    inc=False
            else:
                if arr[n-i-2]>arr[n-i-1]:
                    ans=n-i-1
                    brk=True
    print(ans)