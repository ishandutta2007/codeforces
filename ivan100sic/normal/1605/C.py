t=int(input())
for i in range(t):
    input()
    s=input()
    if 'aa' in s:
        print(2)
    elif 'aba' in s or 'aca' in s:
        print(3)
    elif 'abca' in s or 'acba' in s:
        print(4)
    elif 'abbacca' in s or 'accabba' in s:
        print(7)
    else:
        print(-1)