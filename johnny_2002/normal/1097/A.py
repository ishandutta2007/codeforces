s = input()
a = list(input().split())
for t in a : 
    if (t[0] == s[0] or t[1] == s[1]) : 
        print('YES')
        exit(0)
print('NO')