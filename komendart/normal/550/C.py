def main():
    s = input()
    n = len(s)

    if '0' in s:
        print("YES")
        print('0')
        return
    result = None
    for i in range(n):
        if int(s[i]) % 8 == 0:
            result = s[i]
        for j in range(i + 1, n):
            if int(s[i] + s[j]) % 8 == 0:
                result = s[i] + s[j]
            for k in range(j + 1, n):
                if int(s[i] + s[j] + s[k]) % 8 == 0:
                    result = s[i] + s[j] + s[k]
    if result:
        print("YES")
        print(result)
    else:
        print("NO")

main()