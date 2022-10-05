a=int(input())
for i in range(a):
    s=input()
    if len(s)>10:
        print(s[0]+repr(len(s)-2)+s[len(s)-1])
    else:
        print(s)