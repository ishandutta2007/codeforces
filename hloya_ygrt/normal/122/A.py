def lucky(temp):
    s = str(temp)
    for i in s:
        if i != '4' and i != '7':
            return False
    return True

temp = input()
n = int(temp)

i = 1
while i <= n:
    if lucky(i) and n%i == 0:
        print("YES")
        exit(0)
    i = i + 1


print("NO")