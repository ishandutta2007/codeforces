a = []
a = input().split()

ans = int(0)
ans = int(a[0]) // int(a[2])

if int(a[0]) % int(a[2]) != 0:
    ans  = ans + 1

ans2 = int(0)
ans2  = int(a[1]) // int(a[2])
if int(a[1]) % int(a[2]) != 0:
    ans2  = ans2 + 1
print(ans*ans2)