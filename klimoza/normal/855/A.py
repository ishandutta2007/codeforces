n = int(input())
a = []
for i in range(n):
    st = input()
    if st not in a:
        a.append(st)
        print("NO")
    else:
        print("YES")