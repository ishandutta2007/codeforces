n = int(input())
s = input().strip()

result = False
for i in range(n-4):
    for j in range(1, (n - i - 1) // 4 + 1):
        #print(s[i:i + 4*j+1:j])
        if s[i:i + 4*j + 1:j] == '*****':
            result = True
if result:
    print("yes")
else:
    print("no")