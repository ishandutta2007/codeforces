def get():
    return map(int,input().split())
n=int(input())
for i in range(n):
    x=int(input())
    s=input()
    if x>2:
        print("YES")
        print(2)
        print(s[0],s[1:])
    else:
        if int(s[1])>int(s[0]):
            print("YES")
            print(2)
            print(s[0],s[1])
        else:
            print("NO")