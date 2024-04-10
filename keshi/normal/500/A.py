a,b=map(int,input().split())
s=list(map(int,input().split()))
d=1
while d<b:
    d+=s[d-1]
if d==b:
    print("YES")
else:
    print("NO")