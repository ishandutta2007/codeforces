import re
print(sum(1 if c=='A' else int(c) for c in re.findall(r'10|A|[2-9]', input())))