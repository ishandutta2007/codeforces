s = input()
n = len(s)
k = (n + 19) // 20
x = n // k
st = 0
print(k, (n + k - 1) // k)
y = k - (n % k)
if y == k:
    for i in range(k):
        print(s[st:st + x])
        st += x
else:
    for i in range(k):
        if i < y:
            print("*" + s[st:st + x])
            st += x
        else:
            print(s[st:st + x + 1])
            st += x + 1