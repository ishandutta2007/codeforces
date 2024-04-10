def get():
    return list(map(int,input().split()))
s=input()
d=input()
if len(s)!=len(d):
    print("No")
else:
    f=1
    for i in range(len(s)):
        if (d[i] in 'aeoiu') != (s[i] in 'aeiou'):
            f=0
    if f:
        print("Yes")
    else:
        print("No")