import sys
input=sys.stdin.readline
t=int(input())
for you in range(t):
    l=input().split()
    li=[int(i) for i in l]
    maxa=0
    for i in range(4):
        for j in range(i+1,4):
            z=min(li[i],li[j])
            x=[]
            for k in range(4):
                if(k==i or k==j):
                    continue
                x.append(li[k])
            z=z*min(x)
            maxa=max(maxa,z)
    print(maxa)