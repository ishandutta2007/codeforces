a=[[0,8],[6],[4],[2]]
s='00'+input()
f=0
for i in range(len(s)):
    for j in range(i+1,len(s)):
        b,c=int(s[i]),int(s[j])
        x=a[(b%2*2+c%4)%4]
        for k in x:
            if str(k) in s[j+1:]:
                f=1
                print("YES")
                print(int(str(b)+str(c)+str(k)))
                break
        if f:
            break
    if f:
        break
if not f:
    print("NO")