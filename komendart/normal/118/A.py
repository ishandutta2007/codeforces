s = raw_input()
n_s = ""
for i in s:
    if i not in "AOYEUIaoyeui":
        n_s += '.'
        if 'A' <= i <= 'Z':
            n_s += chr(ord(i) - ord('A') + ord('a'))
        else:
            n_s += i
print n_s